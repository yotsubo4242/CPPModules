#include <fstream>
#include <iostream>
#include <sstream>

bool	validate_infile(std::ifstream &in_file) {
	if (in_file.is_open() == false) {
		std::cerr << "\033[31m Error occured: Input file \033[m" << std::endl;
		return (false);
	}
	return (true);
}

bool	validate_outfile(std::ofstream &out_file) {
	if (out_file.is_open() == false) {
		std::cerr << "\033[31m Error occured: Output file \033[m" << std::endl;
		return (false);
	}
	return (true);
}

std::string	make_replaced_content(std::string content, std::string s1, std::string s2) {
	std::string::size_type 	prev_pos = 0;
	std::string::size_type 	pos = content.find(s1);
	std::size_t				s1_length = s1.length();
	std::string				res;

	while (pos != std::string::npos) {
		res += content.substr(prev_pos, pos - prev_pos);
		res += s2;
		prev_pos = pos + s1_length;
		pos = content.find(s1, pos + s1_length);
	}
	res += content.substr(prev_pos, content.max_size());
	return (res);
}

int	main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "This program need 3 variables ( ./SedIsForLosers <filename> <s1> <s2> )." << std::endl;
		std::cerr << "Please try again..." << std::endl;
		return (1);
	}

	const std::string		in_file_name(argv[1]);
	std::ifstream	in_file(argv[1]);
	const std::string		out_file_name = in_file_name + ".replace";
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		in_file_content;
	std::stringstream	ss;
	std::string		replaced_content;
	
	if (s1.empty()) {
		std::cerr << "\033[31m Error occured: s1 is empty string. \033[m" << std::endl;
		return (1);
	}
	if (!validate_infile(in_file))
		return (1);

	std::ofstream	out_file(out_file_name.c_str());

	if (!validate_outfile(out_file)) {
		in_file.close();
		return (1);
	}
	ss << in_file.rdbuf();
	in_file_content = ss.str();
	replaced_content = make_replaced_content(in_file_content, s1, s2);
	out_file << replaced_content;
	in_file.close();
	out_file.close();
	return (0);
}

#include <fstream>
#include <iostream>
#include <sstream>

bool	validate_files(std::ifstream &in_file, std::ofstream &out_file) {
	if (!in_file) {
		std::cerr << "\033[31m Error occured: Input file \033[m" << std::endl;
		in_file.close();
		out_file.close();
		return (false);
	}
	if (!out_file) {
		std::cerr << "\033[31m Error occured: Output file \033[m" << std::endl;
		in_file.close();
		out_file.close();
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
	}

	const std::string		in_file_name(argv[1]);
	std::ifstream	in_file(argv[1]);
	const std::string		out_file_name = in_file_name + ".replace";
	std::ofstream	out_file(out_file_name.c_str());
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::string		in_file_content;
	std::stringstream	ss;
	std::string		replaced_content;

	if (!validate_files(in_file, out_file))
		return (1);
	ss << in_file.rdbuf();
	in_file_content = ss.str();
	replaced_content = make_replaced_content(in_file_content, s1, s2);
	out_file << replaced_content;
	in_file.close();
	out_file.close();
	return (0);
}
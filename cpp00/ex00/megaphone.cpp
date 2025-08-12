#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 0; argv[i + 1] != NULL; i++)
	{
		for (int j = 0; argv[i + 1][j] != '\0'; j++)
			std::cout << (char)std::toupper(argv[i + 1][j]);
	}
	std::cout << std::endl;
	return (0);
}

#include <iostream>
#include <cctype>

int	main(int arc, char *arg[])
{
	if (arc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string str;
	std::string get;

	for (int i = 1; i < arc; i++)
	{
		str = arg[i];
		for (int j = 0; str[j]; j++)
		{
			str[j] = toupper(str[j]);
		}
		get += str;
	}
	std::cout << get << std::endl;

	return (0);
}
#include <iostream>
#include <cctype>

int	main(int arc, char *arg[])
{
	if (arc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < arc; i++)
	{
		int j = 0;
		while (arg[i][j])
		{
			std::cout << char(toupper(arg[i][j]));
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}
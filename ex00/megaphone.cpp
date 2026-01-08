#include <iostream>
#include <cctype>

int	main(int arc, char *arg[])
{
	int	i = 1;
	int	j = 0;

	if (arc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (i = 1; i < arc; i++)
	{
		while (arg[i][j])
		{
			std::cout << char(toupper(arg[i][j]));
			j++;
		}
		j = 0;
	}
	std::cout << std::endl;
	return (0);
}
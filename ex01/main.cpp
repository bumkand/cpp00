#include "phonebook.hpp"

int	main()
{
	PhoneBook my_Phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			my_Phonebook.addNewContact();
		}
		else if (command == "SEARCH")
        {
            my_Phonebook.searchPhoneBook();
        }
        else if (command == "EXIT")
        {
            break;
        }
	}
	return (0);
}
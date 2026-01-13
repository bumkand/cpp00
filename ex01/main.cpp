#include "phonebook.hpp"

int	main()
{
	PhoneBook my_Phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command) || command == "EXIT")
			break;
		if (command == "ADD")
			my_Phonebook.addNewContact();
		else if (command == "SEARCH")
            my_Phonebook.searchPhoneBook();
        if (std::cin.eof())
			break;
	}
	return (0);
}
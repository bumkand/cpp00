#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_count = 0;
}

std::string PhoneBook::_getInput(std::string str) const
{
	std::string input = "";
	while (input.empty() && !std::cin.eof())
	{
		std::cout << str << std::endl;
		if (!std::getline(std::cin, input))
			return "";
	}
	return (input);
}

void PhoneBook::addNewContact(void)
{
	std::string	input;

	_contacts[_index].setFirstName(_getInput("Input Name"));

	_contacts[_index].setLastName(_getInput("Input Surname"));

	_contacts[_index].setNickName(_getInput("Input Nickname"));

	_contacts[_index].setPhoneNumber(_getInput("Input Number"));

	_contacts[_index].setDarkestSecret(_getInput("Input Secret"));

	_index = (_index + 1) % 8;
	if (_count < 8)
		_count += 1;
}

std::string PhoneBook::_formatString(std::string str) const
{
	if (str.length() > 10)
		return  (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::searchPhoneBook(void) const
{
	if (_count == 0)
	{
		std::cout << "Phone Book Is Empty" << std::endl;
		return;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << "|" << std::setw(10) << i \
			<< "|" << std::setw(10) << _formatString(_contacts[i].getFirstName()) \
			<< "|" << std::setw(10) << _formatString(_contacts[i].getLastName()) \
			<< "|" << std::setw(10) << _formatString(_contacts[i].getNickName()) \
			<< "|" << std::endl;
	}
	std::string indexStr = _getInput("Enter index to display details");
	if (indexStr.length() == 1 && indexStr[0] >= '0' && indexStr[0] <= '7')
	{
		int i = indexStr[0] - '0';
		if (i < _count)
		{
			std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
			std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
			std::cout << "Nickname: " << _contacts[i].getNickName() << std::endl;
			std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Index out of range" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}
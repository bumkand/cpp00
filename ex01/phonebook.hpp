#include "contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _index;
		int	_count;
		std::string _getInput(std::string str) const;
		std::string _formatString(std::string str) const;
	public:
		PhoneBook();
		void addNewContact(void);
		void searchPhoneBook(void) const;
};
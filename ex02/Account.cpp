#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);
	
	std::cout << "[" << (datetime.tm_year + 1900);

	if ((datetime.tm_mon + 1) < 10)
		std::cout << '0';
	std::cout << (datetime.tm_mon + 1);

	if (datetime.tm_mday < 10)
		std::cout << '0';
	std::cout << datetime.tm_mday << "_";

	if (datetime.tm_hour < 10)
		std::cout << '0';
	std::cout << datetime.tm_hour;

	if (datetime.tm_min < 10)
		std::cout << '0';
	std::cout << datetime.tm_min;

	if (datetime.tm_sec < 10)
		std::cout << '0';
	std::cout << datetime.tm_sec << "]";
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" \
		<< "total:" << getTotalAmount() << ";" \
		<< "deposits:" << getNbDeposits() << ";" \
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";" \
		<< "amount:" << _amount << ";" \
		<< "deposits:" << _nbDeposits << ";" \
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "deposit:" << deposit << ";" \
		<< "amount:" << _amount << ";" \
		<< "nb_deposits:" << _nbDeposits << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";" \
			<< "p_amount:" << _amount << ";" \
			<< "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		int	p_amount = _amount;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;

		std::cout << "index:" << _accountIndex << ";" \
			<< "p_amount:" << p_amount << ";" \
			<< "withdrawal:" << withdrawal << ";" \
			<< "amount:" << _amount << ";" \
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}

}

int	Account::checkAmount(void) const
{
	return (_amount);
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" \
		<< "amount:" << _amount << ";" \
		<< "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
	
	_nbAccounts--;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:32:50 by welow             #+#    #+#             */
/*   Updated: 2024/10/31 14:42:42 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

// "Account::" means the function or variable is in the class Account
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int Account::getTotalAmount( void ) { return Account::_totalAmount; }
int Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }


/**
*   @brief create a new account with timestamp, account index and amount
*   @param initial_deposit user input the amount
*	@note 1. initialize can be done after the constructor parameter
*	@note 2. because is astatic so when "_nbAccounts" and "_totalAmount" update,
			 it will update the value when create another account
*/
Account::Account( int initial_deposit )
	: _accountIndex(getNbAccounts()),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << checkAmount() << ";"
                << "created" << std::endl;
}

/**
*   @brief delete the account with timestamp, account index and amount
*	@note 1. this is a destructor, so it will delete the account after
*			 the program finish
*/
Account::~Account( void )
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << checkAmount() << ";"
                << "closed" << std::endl;
}

/**
*   @brief display the account status (for all total account, total amount, total deposit, total withdrawal)
*	@note 1. because this function is a non-member function, so we need to use
*			 the class name to access the static member and function
*	@note 2. non-member function: does not have access the private member declared in the class
*            EXAMPLE: this function doesn't get private member variable
*	@note 3. member function: have access to the private member declared in the class
*            EXAMPLE: "checkAmount" function it access the private member variable
*/
void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
                << "total:" << Account::getTotalAmount() << ";"
                << "deposits:" << Account::getNbDeposits() << ";"
                << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/**
*	@brief display the account status in current update (for each account)
*/
void	Account::displayStatus( void ) const
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "deposits:" << this->_nbDeposits << ";"
                << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
*   @brief check the amount of the account
*   @return the amount of the account
*/
int	Account::checkAmount( void ) const
{
    return this->_amount;
}


/**
*   @brief display the timestamp
*/
void Account::_displayTimestamp( void )
{
    std::cout << "[19920104_091532] ";
}

/**
*   @brief display the amount of the account after deposit
*   @param deposit the amount that user want to deposit
*	@note 1. print the account previous amount
*	@note 2. decrease the amount and total_amount value with the "deposit" value
*	@note 3. update the number of deposit and total number of deposit
*	@note 4. print the updated amount and number of deposit
*/
void Account::makeDeposit( int deposit )
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << checkAmount() << ";" ;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << "deposit:" << deposit << ";" << "amount:" << checkAmount() << ";" << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
*   @brief display the amount of the account after withdrawal
*   @param withdrawal the amount that user want to withdraw
*   @return true with the amount that withdraw, false with print refused
*	@note 1. decrease the amount and total_amount value with the "withdraw" value
*	@note 2. update the number of withdrawal and total number of withdrawal
*	@note 3. print the updated amount and number of withdrawal and return "true"
*/
bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << checkAmount() << ";" << "withdrawal:" ;
    if (checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    this->_nbWithdrawals++;
     std::cout << withdrawal << ";" << "amount:" << checkAmount() << ";" << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
     return true;
}


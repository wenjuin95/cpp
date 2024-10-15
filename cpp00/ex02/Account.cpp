/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:32:50 by welow             #+#    #+#             */
/*   Updated: 2024/10/15 12:17:54 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

//static: these variables are shared by all instances of the class and it keep updating
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//to get these variable value in private we use getter
int Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int Account::getTotalAmount( void ) { return Account::_totalAmount; }
int Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

/*
*   @brief display the account status
*	@note 1. because this function is a non-member function, so we need to use 
*			 the class name to access the static member and function
*/
void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
                << "total:" << Account::getTotalAmount() << ";"
                << "deposits:" << Account::getNbDeposits() << ";"
                << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
*   @brief when create a new account, display the timestamp and account index and amount
*   @param initial_deposit user input the amount
*	@note 1. get the account index for each of the account created and update the number of account
*	@note 2. set the amount of user input
*	@note 3. add the amount to the total_amount when new account created and they have amount
*	@note 4. initialize the number of deposits and withdrawals
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

/*
*   @brief close the account when finish
*/
Account::~Account( void ) {
    this->_displayTimestamp(); // Display the timestamp
    std::cout << "index:" << this->_accountIndex << ";" 
                << "amount:" << this->checkAmount() << ";" 
                << "closed" << std::endl;
}

/*
*   @brief check the amount of the account
*   @return the amount of the account
*	@note const: class member in the function only able to read and can't modify
*/
int	Account::checkAmount( void ) const {
    return this->_amount;
}

/*
*	@brief display the account status
*	@note const: class member in the function only able to read and can't modify
*/
void	Account::displayStatus( void ) const {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "deposits:" << this->_nbDeposits << ";"
                << "withdrawals:" << this->_nbWithdrawals << std::endl;
}



/*
*   @brief display the timestamp
*	@note setw: set the width of the output to 2 (mean 2 digit)
*	@note setfill: fill the empty space with '0'
*	@note year start from 1900 so you get the total year not this year
*/
void Account::_displayTimestamp( void ) {
    time_t  now;
    struct tm *tm;

    now = time(0);
    tm = localtime(&now);
    std::cout << "["
                << tm->tm_year + 1900
                << std::setw(2) << std::setfill('0') << tm->tm_mon + 1
                << std::setw(2) << std::setfill('0') << tm->tm_mday
                << "_"
                << std::setw(2) << std::setfill('0') << tm->tm_hour
                << std::setw(2) << std::setfill('0') << tm->tm_min
                << std::setw(2) << std::setfill('0') << tm->tm_sec
                << "] ";
}

/*
*   @brief display the amount of the account after deposit
*   @param deposit the amount that user want to deposit
*	@note 1. print the account previous amount
*	@note 2. update the amount and total_amount with the "deposit"
*	@note 3. update the number of deposits and total number of deposits
*	@note 4. print the updated amount and number of deposits
*/
void Account::makeDeposit( int deposit ) {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << checkAmount() << ";" ;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << "deposit:" << deposit << ";" << "amount:" << checkAmount() << ";" << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/*
*   @brief display the amount of the account after withdrawal 
*   @param withdrawal the amount that user want to withdraw
*   @return true with the amount that withdraw, false with print refused
*	@note 1. if the amount was more then the amount user have, print refused and return "false"
*	@note 2. if "true" the amount and total amount will decrease from the withdrawal amount
*	@note 3. update the number of withdrawal and total number of withdrawal
*	@note 4. print the updated amount and number of withdrawals and return "true"
*/
bool	Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << this->checkAmount() << ";" << "withdrawal:" ;
    if (checkAmount() < withdrawal) 
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    this->_nbWithdrawals++;
     std::cout << withdrawal << ";" << "amount:" << this->checkAmount() << ";" << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
     return true;
}


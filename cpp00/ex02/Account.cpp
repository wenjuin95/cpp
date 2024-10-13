/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wenjuin <wenjuin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:32:50 by welow             #+#    #+#             */
/*   Updated: 2024/10/13 21:37:09 by wenjuin          ###   ########.fr       */
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

//to get these variable in private we use getter
int Account::getNbAccounts( void ) { return _nbAccounts; }
int Account::getTotalAmount( void ) { return _totalAmount; }
int Account::getNbDeposits( void ) { return _totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

/*
*   @brief check the amount of the account
*   @return the amount of the account
*   @note this function is const because it does not modify the object
*/
int	Account::checkAmount( void ) const {
    return _amount;
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}

/*
*   @brief display the account status
*/
void Account::displayAccountsInfos( void ) {
    _displayTimestamp(); // Display the timestamp
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
                << "total:" << Account::getTotalAmount() << ";"
                << "deposits:" << Account::getNbDeposits() << ";"
                << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
*   @brief when create a new account, display the timestamp and account index and amount
*   @param initial_deposit the initial deposit
*/
Account::Account( int initial_deposit ) {
    _nbDeposits = 0;  //initialize the number of deposits
    _nbWithdrawals = 0; //initialize the number of withdrawals
    _nbAccounts++; // Increment the number of accounts each time a new account is created
    _accountIndex = _nbAccounts - 1; //get the first account index start from 0
    _amount = initial_deposit; // Set the initial deposit
    _totalAmount += initial_deposit; // Increment the total amount each time a new account is created
    _displayTimestamp(); // Display the timestamp
    std::cout << "index:" << _accountIndex << ";" 
                << "amount:" << _amount << ";" 
                << "created" << std::endl;
}

/*
*   @brief close the account when finish
*/
Account::~Account( void ) {
    _displayTimestamp(); // Display the timestamp
    std::cout << "index:" << _accountIndex << ";" 
                << "amount:" << _amount << ";" 
                << "closed" << std::endl;
}

/*
*   @brief display the timestamp
*/
void Account::_displayTimestamp( void ) {
    time_t  now;
    struct tm *tm;

    now = time(0); // Get the current time
    tm = localtime(&now); // Convert the current time to the local time
    std::cout << "["
                << tm->tm_year + 1900 //year start from 1900 so you get the total year not this year
                << std::setw(2) << std::setfill('0') << tm->tm_mon + 1 //+1 is because month start from 0
                << std::setw(2) << std::setfill('0') << tm->tm_mday
                << "_"
                << std::setw(2) << std::setfill('0') << tm->tm_hour
                << std::setw(2) << std::setfill('0') << tm->tm_min
                << std::setw(2) << std::setfill('0') << tm->tm_sec
                << "] ";
}

/*
*   @brief display the amount of the account after deposit or withdrawal
*/
void Account::makeDeposit( int deposit ) {
    _nbDeposits++; // Increment the number of deposits
    _amount += deposit; // Increment the amount
    _totalNbDeposits++; // Increment the total number of deposits
    _totalAmount += deposit; // Increment the total amount
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << _amount + deposit << ";"
                << "nb_deposits:" << _nbDeposits << std::endl;
}

/*
*   @brief display the amount of the account after withdrawal 
*   @return true with the amount that withdraw, false with print refused
*/
bool	Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    _nbWithdrawals++; // Increment the number of withdrawals
    _totalNbWithdrawals++; // Increment the total number of withdrawals
    std::cout << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:" << withdrawal << ";";
    if (withdrawal > _amount) // if the withdrawal is greater than the amount
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    // if the withdrawal is less than the amount
     _amount -= withdrawal; // Decrement the amount
     _totalAmount -= withdrawal; // Decrement the total amount
     std::cout << "amount:" << _amount - withdrawal << ";"
                 << "nb_withdrawals:" << _nbWithdrawals << std::endl;
     return true;
}


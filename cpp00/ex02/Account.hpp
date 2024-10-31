// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once //this is to prevent more then two time include the header file 
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; //name Account as t

	//static: keep updating the value and shared by all instances of the class
	static int	getNbAccounts( void ); //get the number of account
	static int	getTotalAmount( void ); //get the total amount of all account
	static int	getNbDeposits( void ); //get the total number of deposits
	static int	getNbWithdrawals( void ); //get the total number of withdrawals
	static void	displayAccountsInfos( void ); //display the account information

	// constructor: when program execute, it auto create the member with all variable and function
	Account( int initial_deposit );
	
	// destructor: after the program finish, it auto delete the member with all variable and function
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );

	//const: the function will not change the value of the variable
	int		checkAmount( void ) const; //check the amount of the account
	void	displayStatus( void ) const; //display the account status


private:

	static int	_nbAccounts; //number of account
	static int	_totalAmount; //total amount of all account
	static int	_totalNbDeposits; //total number of deposit
	static int	_totalNbWithdrawals; //total number of withdrawal

	static void	_displayTimestamp( void );

	int				_accountIndex; //account index for each account
	int				_amount; //amount of each account
	int				_nbDeposits; //number of deposits of each account
	int				_nbWithdrawals; //number of withdrawals of each account

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */

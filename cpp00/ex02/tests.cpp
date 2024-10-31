// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; //is a dynamic array means it can change the size of the array
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //pair is a container that can store two values of different types

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; //array of amount
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); //size of the array
	accounts_t				accounts( amounts, amounts + amounts_size ); //initialize the account with the amount for each account
	accounts_t::iterator	acc_begin	= accounts.begin(); //beginning container of the account
	accounts_t::iterator	acc_end		= accounts.end(); //end container of the account

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; //array of deposit
	size_t const		d_size( sizeof(d) / sizeof(int) ); //size of the array
	ints_t				deposits( d, d + d_size ); //initialize the deposit with the amount for each account
	ints_t::iterator	dep_begin	= deposits.begin(); //beginning container of the deposit
	ints_t::iterator	dep_end		= deposits.end(); //end container of the deposit

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; //array of withdrawal
	size_t const		w_size( sizeof(w) / sizeof(int) ); //size of the array
	ints_t				withdrawals( w, w + w_size ); //initialize the withdrawal with the amount for each account
	ints_t::iterator	wit_begin	= withdrawals.begin(); //beginning container of the withdrawal
	ints_t::iterator	wit_end		= withdrawals.end(); //end container of the withdrawal

	//display the account information
	// std::cout << "Initial accounts information:" << std::endl; //visualize
	Account::displayAccountsInfos();
	// std::cout << "\n" << "get amount of each account:" << std::endl; //visualize
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//loop through each account and deposit the amount
	std::cout << "\n" << "loop through each account and deposit the amount" << std::endl;
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}
	
	//display the account information after deposit
	// std::cout << "\n" << "result after deposit:" << std::endl; //visualize
	Account::displayAccountsInfos();
	// std::cout << "\n" << "update amount of each account:" << std::endl; //visualize
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//loop through each account and withdraw the amount
	// std::cout << "\n" << "loop through each account and withdraw the amount:" << std::endl; //visualize
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	//display the account information after withdrawal
	// std::cout << "\n" << "result after withdraw:" << std::endl; //visualize
	Account::displayAccountsInfos();
	// std::cout << "\n" << "update amount of each account:" << std::endl; //visualize
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

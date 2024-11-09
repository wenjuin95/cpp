// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector> // vector
#include <algorithm> //for_each
#include <functional> //mem_fun_ref
#include "Account.hpp"
#include <iostream>


int		main( void ) {

	/**
	 * "std::vector" represents a dynamic array. It can grow in size dynamically
	 * 	std::vector vs array:
	 * 	- std::vector: can handle huge number of element and it can grow in size dynamically
	 *  - array: can handle only a fixed number of element
	 * EXAMPLE: std::vector<Account::t>	is to store a collection of Account objects in a dynamic array.
	 * 
	 * "std::pair" is a container that can store two values of different types.
	 * EXAMPLE: std::pair<accounts_t::iterator, ints_t::iterator>	is to store accounts_t::iterator and ints_t::iterator.
	 * 
	 * "accounts_t::iterator" is to loop through the accounts vector.
	 * "ints_t::iterator" is to loop through the deposits and withdrawals vector.
	*/
	typedef std::vector<Account::t>							  accounts_t; //vector of Account objects
	typedef std::vector<int>								  ints_t; //vector of int
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //pair of account with "vector of account" and "vector of int"

	/**
	 * - amounts: a pointer to the first element in the array
	 * - amounts + amounts_size: a pointer to the last element in the array 
	*/
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; //array of amount
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); //size of the amount array
	accounts_t				accounts( amounts, amounts + amounts_size ); //vector of Account objects
	accounts_t::iterator	acc_begin	= accounts.begin(); //pointer of start in vector
	accounts_t::iterator	acc_end		= accounts.end(); //pointer of end in vector

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) ); 
	ints_t				deposits( d, d + d_size ); 
	ints_t::iterator	dep_begin	= deposits.begin(); 
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) ); 
	ints_t				withdrawals( w, w + w_size ); 
	ints_t::iterator	wit_begin	= withdrawals.begin(); 
	ints_t::iterator	wit_end		= withdrawals.end(); 

	//display the account information
	Account::displayAccountsInfos();
	/**
	 * "std::for_each(....)" is a loop through the accounts vector
	 * - first agument: pointer of first element in the accounts vector
	 * - second argument: pointer of last element in the accounts vector
	 * - third argument: the function to call
	 * 		- std::mem_fun_ref ::  convert a member function into a function object
	 * 		(removed in C++ 17)
	*/
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//loop through each account and deposit the amount
	for ( acc_int_t it( acc_begin, dep_begin ); //loop through the accounts and deposits vector
		  it.first != acc_end && it.second != dep_end; //if the first "pair" iterator and the second "pair" iterator is not at the end of the vector
		  ++(it.first), ++(it.second) ) { //increment the first "pair" iterator and the second "pair" iterator

		(*(it.first)).makeDeposit( *(it.second) ); //make the deposit
	}
	
	//display the account information after deposit
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	//loop through each account and withdraw the amount
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	//display the account information after withdrawal
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

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
	typedef std::vector<Account::t>							  accounts_t; 
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	/**
	 * "accounts( amounts, amounts + amounts_size );" initialize the accounts vector with the range of elements from the amount array
	 * - amounts: a pointer to the first element in the array
	 * - amounts + amounts_size: a pointer to the last element in the array
	 * 
	 * "accounts.begin()" is to get the iterator to the first element in the accounts vector.
	 * "accounts.end()" is to get the iterator to the last element in the accounts vector. 
	*/
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; 
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin(); 
	accounts_t::iterator	acc_end		= accounts.end();

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
	 * "std::for_each(....)" is to loop through the accounts vector
	 * - first agument: the iterator to the first element in the accounts vector
	 * - second argument: the iterator to the last element in the accounts vector
	 * - third argument: the function to call for each element in the accounts vector
	 * - std::mem_fun_ref is to call the member function of the Account object
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

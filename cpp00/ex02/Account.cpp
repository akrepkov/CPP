/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:03:41 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/06 17:35:12 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

//read about this pointer
//  ‘this’ pointer is not available in static member functions 
//  as static member functions can be called without any object (with class name).

//initialize total numbers for incrementing
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


//timestamp - create a struct, use setfill for not doubled numbers, arrange width 2. Year starts from 1900, month starts with 0
void	Account::_displayTimestamp( void ){
	time_t currentTime = std::time(0);
	struct tm tt;
	time(&currentTime);
	tt = *localtime(&currentTime);
	std::cout << "[" << tt.tm_year + 1900 
		<< std::setfill('0') << std::setw(2) << tt.tm_mon + 1 
		<< std::setfill('0') << std::setw(2) << tt.tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << tt.tm_hour 
		<< std::setfill('0') << std::setw(2) << tt.tm_min 
		<< std::setfill('0') << std::setw(2) << tt.tm_sec << "]";
}

Account::Account() {}; //empty constructor; Definition of a default constructor outside
	// of class definition (the class must contain a declaration (1)).
	//If you don't define ANY constructors, a default constructor is automatically provided. 
	//If you define constructors with parameters, that default constructor is NOT provided.

Account::Account( int initial_deposit ){
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = Account::_totalNbDeposits;
	this->_nbWithdrawals = Account::_totalNbWithdrawals;
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";created" << std::endl;
	Account::_nbAccounts++;
}

//read more about getters:
int	Account::getNbAccounts( void ){ //why account::
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";closed" << std::endl;
}

void Account::makeDeposit( int deposit ){
	_displayTimestamp();
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	int fullAmount = this->_amount + deposit;
	std::cout << " index:" << this->_accountIndex << ";p_amount:" \
	<< this->_amount << ";deposit:" << deposit << ";amount:" << fullAmount \
	<< ";nb_deposits:" << this->_nbDeposits <<std::endl;
	this->_amount = fullAmount;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" \
	<< this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount){
		std::cout << "refused" <<std::endl;
		return false;
	}
	else {
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount \
		<< ";nb_withdrawals:" << this->_nbWithdrawals <<std::endl;
		Account::_totalAmount -= withdrawal;
	}
	return true;
}

void Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() \
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals <<std::endl;
}

void Account::displayStatus(void) const{ //why const
	_displayTimestamp();
	
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals <<std::endl;
}


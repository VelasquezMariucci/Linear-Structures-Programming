//
// Created by esvel on 23/09/2024.
//

#include "BankAccount.h"

#include <iostream>

/*
     *@brief constructor that takes in the starting balance, a unique account id, and the
     *holder's name.
     *
     *@param balance float.
     *@param accountID string unique account id.
     *@param accountHolder string account holder's name
     */
BankAccount::BankAccount(float balance, std::string accountID, std::string accountHolder)
{
    this->balance = balance;
    this->accountID = accountID;
    this->accountHolder = accountHolder;
}

void BankAccount::deposit(float amount)
{
    balance += amount;
}

void BankAccount::withdraw(float amount)
{
    balance -= amount;
}

void BankAccount::checkBalance()
{
    std::cout << accountHolder << " (ID): " << accountID << "\n" << "Balance: " << balance << "\n" << std::endl;
}

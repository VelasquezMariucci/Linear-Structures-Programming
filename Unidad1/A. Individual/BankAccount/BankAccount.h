//
// Created by esvel on 23/09/2024.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

/*
 *@brief Model class to handle a Bank Account
 *
 *This class provides  functions to deposit, withdraw and checking the balance.
 */
class BankAccount
{
public:
    /*
     *@brief constructor that takes in the starting balance, a unique account id, and the
     *holder's name.
     *
     *@param balance float.
     *@param accountID string unique account id.
     *@param accountHolder string account holder's name
     */
    BankAccount(float balance, std::string accountID, std::string accountHolder);
    ~BankAccount() = default;

    void deposit(float amount);
    void withdraw(float amount);
    void checkBalance();

private:
    float balance;
    std::string accountID;
    std::string accountHolder;
};


#endif //BANKACCOUNT_H

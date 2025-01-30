#include <iostream>

#include "BankAccount.h"

/*
 *Diseña una clase llamada “CuentaBancaria” que tenga atributos como
 *número de cuenta, saldo y titular de la cuenta. Implementa métodos
 *para depositar dinero, retirar dinero y consultar el saldo. Luego, crea
 *objetos de esta clase y realiza operaciones bancarias para demostrar su
 *funcionamiento.
 */

int main()
{
    //Bank account intances
    BankAccount* BobsAccount = new BankAccount(25000, "0001", "Bob");
    BankAccount* MarysAccount = new BankAccount(30000, "0002", "Mary");

    //check balances
    BobsAccount->checkBalance();
    MarysAccount->checkBalance();

    //deposits
    BobsAccount->deposit(5000);
    MarysAccount->deposit(1000);

    //check balances
    BobsAccount->checkBalance();
    MarysAccount->checkBalance();

    //withdraws
    BobsAccount->withdraw(743.12);
    MarysAccount->withdraw(16343.18);

    //check balances
    BobsAccount->checkBalance();
    MarysAccount->checkBalance();

    return 0;
}

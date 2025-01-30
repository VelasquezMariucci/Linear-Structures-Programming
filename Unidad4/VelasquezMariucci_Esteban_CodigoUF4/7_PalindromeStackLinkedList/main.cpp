#include <iostream>
#include "../Structures/Stack_LinkedList.h"

/*Escribir un programa que utilice una Pila (construida como lista
enlazada) para comprobar si una determinada frase/palabra es un palíndromo.*/

/**
 * @brief Checks if a given string is a palindrome using a stack.
 *
 * This function uses a stack to reverse the string and compare it
 * with the original.
 *
 * @param word The input string to check.
 * @return true if the input string is a palindrome, false otherwise.
 */
bool isPalindrome(std::string word)
{
    Stack_LinkedList<char>* stack = new Stack_LinkedList<char>();

    for (char c : word)
    {
        stack->push(c);
    }

    const int size = stack->getSize();
    bool isPalindrome = true;

    for (char c : word)
    {
        if (stack->pop() != c)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // Create stack linked list
    LinkedList<char>* stackLinkedList = new LinkedList<char>();

    std::string r = "rotor";
    std::string h = "hello";
    std::string r2 = "radar";

    // check palindrome
    std::cout << r << ": " << (isPalindrome(r) ? "Yes" : "No") << std::endl;
    std::cout << h << ": " << (isPalindrome(h) ? "Yes" : "No") << std::endl;
    std::cout << r2 << ": " << (isPalindrome(r2) ? "Yes" : "No") << std::endl;

    return 0;
}

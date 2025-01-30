
#include <iostream>
#include <string>
#include "Juego.h"

void delayedPrint(std::string text)
{
    std::cout << text;
}


// Juego principal: Dragones y Mazmorras
int main() {
    std::srand(std::time(nullptr));
    int random_number = std::rand() % 6 + 1;

    std::cout << random_number << std::endl;

    std::srand(std::time(nullptr));

    for(int i = 0; i < 2; i++) {
        int random_number = std::rand() % 6 + 1;
        std::cout << random_number << std::endl;
    }

    Juego juego;
    juego.iniciar();
    return 0;
}

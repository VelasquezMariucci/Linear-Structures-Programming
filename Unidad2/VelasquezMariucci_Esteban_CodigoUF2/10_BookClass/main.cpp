#include <iostream>

#include "Book.h"

/*Crea una clase "Libro" con atributos de título y autor. Incluye métodos para
obtener y establecer los valores de los atributos. Luego, crea un objeto de la
clase "Libro" y muestra su título y autor.
*/

int main()
{
    // Variables to feed pointers.
    std::string title = "Cien Anios de Soledad";
    std::string author = "Gabriel Garcia Marquez";

    // Pointers to feed book.
    std::string* pTitle = &title;
    std::string* pAuthor = &author;

    Book* person = new Book(pTitle, pAuthor);

    std::cout << "First) Title: " << person->getTitle() << ", Author:" << person->getAuthor() << std::endl;

    title = "12 Rules of Life";
    author = "Jordan B. Peterson";

    person->setTitle(pTitle);
    person->setAuthor(pAuthor);

    std::cout << "Second) Title: " << person->getTitle() << ", Author:" << person->getAuthor() << std::endl;

    return 0;


    return 0;
}

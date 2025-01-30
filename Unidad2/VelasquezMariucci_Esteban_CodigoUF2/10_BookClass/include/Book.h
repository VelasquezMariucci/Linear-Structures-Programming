//
// Created by esvel on 27/10/2024.
//

#ifndef BOOK_H
#define BOOK_H
#include <string>


class Book
{
private:
    std::string* title;
    std::string* author;

public:
    Book(std::string* titulo, std::string* author);

    ~Book() = default;

    std::string getTitle();

    std::string getAuthor();

    void setTitle(std::string* title);

    void setAuthor(std::string* author);
};


#endif //BOOK_H

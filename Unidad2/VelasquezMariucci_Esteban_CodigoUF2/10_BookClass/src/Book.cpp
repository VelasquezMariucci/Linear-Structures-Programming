//
// Created by esvel on 27/10/2024.
//

#include "Book.h"

Book::Book(std::string* titulo, std::string* author)
{
    this->title = titulo;
    this->author = author;
}

std::string Book::getTitle()
{
    return *title;
}

std::string Book::getAuthor()
{
    return *author;
}

void Book::setTitle(std::string* title)
{
    this->title = title;
}

void Book::setAuthor(std::string* author)
{
    this->author = author;
}
#include "book.h"


Book::Book(const std::string &title, const std::string &author, const unsigned int &year, const unsigned int &price) :
            _title(title), _author(author), _year(year), _price(price) {};

Book& Book::operator=(const Book &other) {
    _title = other._title;
    _author = other._author;
    _year = other._year;
    _price = other._price;
    return *this;
}
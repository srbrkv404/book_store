#include "book.h"

Book::Book(const std::string &title, const std::string &author, const unsigned int &year, const unsigned int &price) :
            _title(title), _author(author), _year(year), _price(price) {};

Book::Book(const Book &other) : _title(other._title), _author(other._author),
            _year(other._year), _price(other._price) {};

Book& Book::operator=(const Book &other) {
    if (this != &other) {
        _title = other._title;
        _author = other._author;
        _year = other._year;
        _price = other._price;
    }
    return *this;
}

Book::Book(Book &&other) noexcept :
        _title(std::move(other._title)), _author(std::move(other._author)),
            _year(std::move(other._year)), _price(std::move(other._price)) {};

Book& Book::operator=(Book &&other) noexcept {
    if (this != &other) {
        _title = std::move(other._title);
        _author = std::move(other._author);
        _year = std::move(other._year);
        _price = std::move(other._price);
    }
    return *this;
}

bool Book::operator==(const Book& other) const {
    return _title == other._title && _author == other._author
        && _year == other._year && _price == other._price;
}
bool Book::operator<(const Book& other) const {
    if (_title != other._title) {
        return _title < other._title;
    }
    if (_author != other._author) {
        return _author < other._author;
    }
    return _year < other._year;
}
bool Book::operator>(const Book& other) const {
    return other < *this;
}

std::string Book::getTitle() const {
    return _title;
}
std::string Book::getAuthor() const {
    return _author;
}
unsigned int Book::getYear() const {
    return _year;
}
unsigned int Book::getPrice() const {
    return _price;
}

void Book::setTitle(const std::string &title) {
    _title = title;
    return;
}
void Book::setAuthor(const std::string &author) {
    _author = author;
    return;
}
void Book::setYear(const unsigned int &year) {
    _year = year;
    return;
}
void Book::setPrice(const unsigned int &price) {
    _price = price;
    return;
}

void Book::print() const {
    std::cout << _title << std::endl;
    std::cout << _author << std::endl;
    std::cout << _year << std::endl;
    std::cout << _price << std::endl;
}
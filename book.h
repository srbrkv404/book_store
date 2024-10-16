#ifndef BOOK_H
#define BOOK_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// pravilo 5
// razdelit na h i cpp
// dobavit const & vezde
// book.print() 


class Book {
    std::string _title;
    std::string _author;
    unsigned int _year;
    unsigned int _price;

    public:
        Book (const std::string &title, const std::string &author, const unsigned int &year, const unsigned int &price);
        
        Book& operator=(const Book &other);

        std::string getTitle() const {
            return _title;
        }
        std::string getAuthor() const {
            return _author;
        }
        unsigned int getYear() const {
            return _year;
        }
        unsigned int getPrice() const {
            return _price;
        }

        void setTitle(const std::string &title) {
            _title = title;
            return;
        }
        void setAuthor(const std::string &author) {
            _author = author;
            return;
        }
        void setYear(const unsigned int &year) {
            _year = year;
            return;
        }
        void setPrice(const unsigned int &price) {
            _price = price;
            return;
        }

        bool operator==(const Book& other) const {
            return _title == other._title && _author == other._author && _year == other._year;
        }

        bool operator<(const Book& other) const {
            if (_title != other._title) {
                return _title < other._title;
            }
            if (_author != other._author) {
                return _author < other._author;
            }
            return _year < other._year;
        }

        bool operator>(const Book& other) const {
            return other < *this;
        }

};

#endif 
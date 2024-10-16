#ifndef BOOK_H
#define BOOK_H


#include <iostream>
#include <string>


class Book {
    std::string _title;
    std::string _author;
    unsigned int _year;
    unsigned int _price;

    public:
        Book(const std::string &title, const std::string &author, const unsigned int &year, const unsigned int &price);
        Book(const Book &other);
        Book& operator=(const Book &other);
        Book(Book &&other) noexcept;
        Book& operator=(Book &&other) noexcept;

        bool operator==(const Book& other) const;
        bool operator<(const Book& other) const;
        bool operator>(const Book& other) const;

        std::string getTitle() const;
        std::string getAuthor() const;
        unsigned int getYear() const;
        unsigned int getPrice() const;

        void setTitle(const std::string &title);
        void setAuthor(const std::string &author);
        void setYear(const unsigned int &year);
        void setPrice(const unsigned int &price);

        void print() const;
};

#endif 
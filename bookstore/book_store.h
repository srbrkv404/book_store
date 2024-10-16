#pragma once

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <vector>
#include <algorithm>
#include "../book/book.h"

enum class SortType {
    Title,
    Author,
    Year
};

class BookStore {
    std::vector <Book> _books;
    
    BookStore() {}

    public:
        BookStore(const BookStore &other) = delete;
        void operator=(const BookStore &other) = delete;
        
        static BookStore& getInstance() {
            static BookStore _bookstore;
            return _bookstore;
        }
        
        void addBook(const Book &book);
        void removeBook(const std::string &title);
        Book * findBook(const std::string &title);

        std::vector <Book> listBook(const SortType &sortType);
        std::vector <Book> findBooksInPriceRange(const unsigned int &minPrice, const unsigned int &maxPrice);
};

#endif
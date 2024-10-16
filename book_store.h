#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <vector>
#include <algorithm>
#include "book.h"


// pravilo 5
// razdelit na h i cpp
// dobavit const &

enum class SortType {
    Title,
    Author,
    Year
};


class BookStore {
    std::vector <Book> books;
    
    BookStore ();

    static BookStore* _bookstore;

    public:
        BookStore(const BookStore &other) = delete;
        void operator=(const BookStore &other) = delete;
        
        static BookStore* getInstance() {
            if (_bookstore == nullptr) {
                _bookstore = new BookStore;
            }

            return _bookstore;
        }
        
        
        void addBook(Book _book) {
            books.push_back(_book);
        }
        void removeBook(std::string _title) {
            if (!books.size()) {
                std::cout << "BookStore is empty!" << std::endl;
                return;
            }

            auto it = books.begin();
            while (it != books.end()) {
                if ((*it).getTitle() == _title) {
                    books.erase(it);
                    std::cout << "Книга удалена." << std::endl;
                    return;
                }
                it++;
            }
            std::cout << "Эту книгу нельзя удалить, так как ее нет." << std::endl;
            return;
        }
        Book * findBook(std::string _title) {
            auto it = books.begin();
            while (it != books.end()) {
                if ((*it).getTitle() == _title) {
                    return &(*it);
                }
                it++;
            }
            return nullptr;
        }
        std::vector <Book> listBook(SortType sortType) {
            if (!books.size()) {
                std::cout << "Книг нет." << std::endl;
                return books;
            }
            std::vector <Book> sorted_books = books;
            switch (sortType) {
                case SortType::Title:
                    std::sort(sorted_books.begin(), sorted_books.end(), 
                        [](const Book &a, const Book &b) {
                        return a.getTitle() < b.getTitle();
                        }
                    );
                    break;
                case SortType::Author:
                    std::sort(sorted_books.begin(), sorted_books.end(),
                        [](const Book &a, const Book &b) {
                        return a.getAuthor() < b.getAuthor();
                        }
                    );
                    break;
                case SortType::Year:
                    std::sort(sorted_books.begin(), sorted_books.end(),
                        [](const Book &a, const Book &b) {
                        return a.getYear() < b.getYear();
                    }
                );
                break;
            }
            return sorted_books;
        }

        std::vector <Book> findBooksInPriceRange(unsigned int minPrice, unsigned int maxPrice) {
            if (minPrice > maxPrice) {
                std::cout << "Wronge range of price!" << std::endl;
                return {};
            }
            std::vector <Book> result;
            auto it = books.begin();
            while (it != books.end()) {
                if ((*it).getPrice() >= minPrice && (*it).getPrice() <= maxPrice) {
                    result.push_back(*it);
                }
                it++;
            }
            if (!result.size()) {
                std::cout << "В данном ценовом диапозоне книг нет." << std::endl;
            }
            return result;
        }

};

#endif
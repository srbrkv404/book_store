#include "book_store.h"

void BookStore::addBook(const Book &book) {
    _books.push_back(book);
    std::cout << "Книга добавлена." << std::endl << std::endl;
}
void BookStore::removeBook(const std::string &title) {
    if (!_books.size()) {
        std::cout << "BookStore is empty!" << std::endl;
        return;
    }

    auto it = _books.begin();
    while (it != _books.end()) {
        if ((*it).getTitle() == title) {
            _books.erase(it);
            std::cout << "Book removed." << std::endl;
            return;
        }
        it++;
    }
    std::cout << "This book cannot be deleted because it does not exist." << std::endl;
    return;
}
Book * BookStore::findBook(const std::string &title) {
    auto it = _books.begin();
    while (it != _books.end()) {
        if ((*it).getTitle() == title) {
            std::cout << "The book has been found." << std::endl << std::endl;
            return &(*it);
        }
        it++;
    }
    std::cout << "The book has not been found." << std::endl << std::endl;
    return nullptr;
}

std::vector <Book> BookStore::listBook(const SortType &sortType) {
    if (!_books.size()) {
        std::cout << "Книг нет." << std::endl;
        return _books;
    }
    std::vector <Book> sorted_books = _books;
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
        default:
            break;
    }
    return sorted_books;
}
std::vector <Book> BookStore::findBooksInPriceRange(const unsigned int &minPrice, const unsigned int &maxPrice) {
    if (minPrice > maxPrice) {
        std::cout << "Wronge range of price!" << std::endl;
        return {};
    }
    std::vector <Book> result;
    auto it = _books.begin();
    while (it != _books.end()) {
        if ((*it).getPrice() >= minPrice && (*it).getPrice() <= maxPrice) {
            result.push_back(*it);
        }
        it++;
    }
    if (!result.size()) {
        std::cout << "There are no books in this price range." << std::endl;
    }
    return result;
}
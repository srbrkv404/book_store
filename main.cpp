#include <exception>
#include <iostream>
#include <new>
#include <ostream>
#include "bookstore/book_store.h"

int main() {
    BookStore &bookstore = BookStore::getInstance();

    try {
        while (true) {
            std::cout << "Choose the option:" << std::endl;
            std::cout << "1. Add book" << std::endl;
            std::cout << "2. Remove book" << std::endl;
            std::cout << "3. Find book by title" << std::endl;
            std::cout << "4. Show all books (sort by title/author/year of publication)" << std::endl;
            std::cout << "5. Find books in price range" << std::endl;
            std::cout << "6. Quit" << std::endl << std::endl;

            unsigned int option;
            std::cin >> option;

            switch (option) {
                case 1: {
                    std::string title;
                    std::string author;
                    unsigned int year;
                    unsigned int price;
                    std::cout << "Enter the book title: ";
                    std::cin >> title;
                    std::cout << "Enter the book author: ";
                    std::cin >> author;
                    std::cout << "Enter the book year of publication: ";
                    std::cin >> year;
                    std::cout << "Enter the book price: ";
                    std::cin >> price;
                    std::cout << std::endl;
                    Book book(title, author, year, price);
                    bookstore.addBook(book);
                    break;
                }
                case 2: {
                    std::string title;
                    std::cout << "Enter the book title: ";
                    std::cin >> title;
                    std::cout << std::endl;
                    bookstore.removeBook(title);
                    break;
                }
                case 3: {
                    std::string title;
                    std::cout << "Enter the book title: ";
                    std::cin >> title;
                    std::cout << std::endl;
                    Book *book = bookstore.findBook(title);
                    break;
                }
                case 4: {
                    SortType sortType;
                    std::cout << "Choose the sort type:\n1. By title.\n2. By author.\n3. By year of publication" << std::endl;
                    int sortNum;
                    std::cin >> sortNum;
                    switch (sortNum) {
                        case 1:
                            sortType = SortType::Author;
                            break;
                        case 2:
                            sortType = SortType::Title;
                            break;
                        case 3:
                            sortType = SortType::Year;
                            break;
                        default:
                            std::cout << "Invalid sort type." << std::endl << std::endl;
                            continue;
                    }
                    std::vector <Book> listBooks;
                    listBooks = bookstore.listBook(sortType);
                    for (const auto &book : listBooks) {
                        std::cout << "------------------" << std::endl;
                        book.print();
                    }
                    std::cout << "------------------" << std::endl;
                    break;
                }
                case 5: {
                    unsigned int minPrice, maxPrice;
                    std::cout << "Enter the minimal price: ";
                    std::cin >> minPrice;
                    std::cout << std::endl << "Enter the maximal price: ";
                    std::cin >> maxPrice;
                    std::cout << std::endl;
                    std::vector <Book> listBooks;
                    listBooks = bookstore.findBooksInPriceRange(minPrice, maxPrice);
                    for (const auto &book : listBooks) {
                        std::cout << "------------------" << std::endl;
                        book.print();
                    }
                    std::cout << "------------------" << std::endl;
                    break;
                }
                case 6: {
                    return 0;
                }
                default:
                    return 0;
            }
        }
    } catch (const std::bad_alloc &error) {
        std::cout << "Bad allocation of memory: " << error.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Something went wrong: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Something went wrong!" << std::endl;
    }
    return 0;
}
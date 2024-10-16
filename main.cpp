#include <exception>
#include <iostream>
#include <new>
#include <ostream>
#include "book_store.h"

int main() {
    
    BookStore *bookstore = BookStore::getInstance();

    try {
        while (true) {
            std::cout << "Выберите опцию:" << std::endl;
            std::cout << "1. Добавить книгу" << std::endl;
            std::cout << "2. Удалить книгу" << std::endl;
            std::cout << "3. Найти книгу по названию" << std::endl;
            std::cout << "4. Показать все книги (сортировка по названию/автору/году издания)" << std::endl;
            std::cout << "5. Найти книги в ценовом диапазоне" << std::endl;
            std::cout << "6. Выйти" << std::endl << std::endl;

            unsigned int option;
            std::cin >> option;

            switch (option) {
                case 1: {
                    std::string title;
                    std::string author;
                    unsigned int year;
                    unsigned int price;
                    std::cout << "Введите название книги: ";
                    std::cin >> title;
                    std::cout << "Введите автора книги: ";
                    std::cin >> author;
                    std::cout << "Введите год издания: ";
                    std::cin >> year;
                    std::cout << "Введите цену: ";
                    std::cin >> price;
                    std::cout << std::endl;
                    Book book(title, author, year, price);
                    bookstore->addBook(book);
                    std::cout << "Книга добавлена." << std::endl << std::endl;
                    std::cout << book.getTitle() << " " << book.getAuthor() << std::endl;
                    break;
                }
                case 2: {
                    std::string title;
                    std::cout << "Введите название книги: ";
                    std::cin >> title;
                    std::cout << std::endl;
                    bookstore->removeBook(title);
                    break;
                }
                case 3: {
                    std::string title;
                    std::cout << "Введите название книги: ";
                    std::cin >> title;
                    std::cout << std::endl;
                    Book *book = bookstore->findBook(title);
                    if (book == nullptr) {
                        std::cout << "Такой книги не нашлось." << std::endl << std::endl;
                    } else {
                        std::cout << "Книга найдена." << std::endl << std::endl;
                    }
                    break;
                }
                case 4: {
                    SortType sortType;
                    std::cout << "Выберите тип сортировки:\n1. По названиям.\n2. По авторам.\n3. По году издания" << std:: endl;
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
                            break;
                    }
                    std::vector <Book> listBooks;
                    listBooks = bookstore->listBook(sortType);
                    for (const auto &book : listBooks) {
                        std::cout << "------------------" << std::endl;
                        std::cout << book.getTitle() << std::endl;
                        std::cout << book.getAuthor() << std::endl;
                        std::cout << book.getYear() << std::endl;
                        std::cout << book.getPrice() << std::endl;
                    }
                    std::cout << "------------------" << std::endl;
                    break;
                }
                case 5: {
                    unsigned int minPrice, maxPrice;
                    std::cout << "Введите минимальную цену: ";
                    std::cin >> minPrice;
                    std::cout << std::endl << "Введите максимальную цену: ";
                    std::cin >> maxPrice;
                    std::cout << std::endl;
                    std::vector <Book> listBooks;
                    listBooks = bookstore->findBooksInPriceRange(minPrice, maxPrice);
                    for (const auto &book : listBooks) {
                        std::cout << "------------------" << std::endl;
                        std::cout << book.getTitle() << std::endl;
                        std::cout << book.getAuthor() << std::endl;
                        std::cout << book.getYear() << std::endl;
                        std::cout << book.getPrice() << std::endl;
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
    }
    return 0;
}
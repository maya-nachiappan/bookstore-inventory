//
//  bookstore.cpp
//  bookstore inventory
//
//  Created by maya nachiappan on 11/4/24.
//

#include "bookstore.hpp"
namespace bookstore {

// Overloading the << operator for easy display of book details
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "ID: " << book.id << ", Title: " << book.title
       << ", Author: " << book.author << ", Release Date: " << book.releaseDate;
    return os;
}

// Constructor to initialize the bookstore address
Bookstore::Bookstore(const std::string& addr) : address(addr) {}

// Function to add a book to the inventory
void Bookstore::addBook(const Book& newBook) {
    // Check if the book with the same ID already exists
    for (const auto& book : inventory) {
        if (book.id == newBook.id) {
            std::cout << "Book with ID " << newBook.id << " already exists. Use a different ID." << std::endl;
            return;
        }
    }
    inventory.push_back(newBook); // Add new book if it doesn't exist
    std::cout << "Book added: " << newBook << std::endl;
}

// Function to find a book by title
Book* Bookstore::findBook(const std::string& title) {
    for (auto& book : inventory) {
        if (book.title == title) {
            return &book;
        }
    }
    return nullptr; // Return nullptr if book not found
}

// Function to display all books in the inventory
void Bookstore::displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& book : inventory) {
        std::cout << book << std::endl;
    }
}

// Function to display the bookstore address
void Bookstore::displayAddress() const {
    std::cout << "Bookstore Address: " << address << std::endl;
}

} // namespace bookstore

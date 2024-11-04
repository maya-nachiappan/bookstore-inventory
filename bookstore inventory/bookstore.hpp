//
//  bookstore.hpp
//  bookstore inventory
//
//  Created by maya nachiappan on 11/4/24.
//

#ifndef bookstore_hpp
#define bookstore_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

namespace bookstore {

struct Book {
    std::string title;
    std::string author;
    std::string releaseDate; // Format: YYYY-MM-DD
    int id; // Unique identifier for the book
    
    // Overloading the << operator for easy display of book details
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

class Bookstore {
private:
    std::vector<Book> inventory;
    std::string address; // Store the bookstore's address
    
public:
    // Constructor to initialize the bookstore address
    Bookstore(const std::string& addr);
    
    // Function to add a book to the inventory
    void addBook(const Book& newBook);
    
    // Function to find a book by title
    Book* findBook(const std::string& title);
    
    // Function to display all books in the inventory
    void displayInventory() const;
    
    // Function to display the bookstore address
    void displayAddress() const;
};

} // namespace bookstore

#endif /* bookstore_hpp */

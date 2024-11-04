//
//  main.cpp
//  bookstore inventory
//
//  Created by maya nachiappan on 10/30/24.
//
#include <iostream>
#include "bookstore.hpp"
using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add a Book\n";
    cout << "2. Find a Book\n";
    cout << "3. Display Inventory\n";
    cout << "4. Display Bookstore Address\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    // Initialize the bookstore with an address
    bookstore::Bookstore bookstore("421 Telegraph st, Berkelety, CA 69420");

    // Display the menu once
    displayMenu();

    int choice;
    while (true) {
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the integer input

        switch (choice) {
            case 1: {
                bookstore::Book newBook;
                cout << "\nEnter details for the book:\n";
                
                cout << "Title: ";
                getline(cin, newBook.title);
                
                cout << "Author: ";
                getline(cin, newBook.author);
                
                cout << "Release Date (YYYY-MM-DD): ";
                getline(cin, newBook.releaseDate);
                
                cout << "ID (unique integer): ";
                cin >> newBook.id;
                cin.ignore(); // To ignore the newline character after the integer input
                
                bookstore.addBook(newBook);
                break;
            }
            case 2: {
                string searchTitle;
                cout << "\nEnter the title of the book to find: ";
                getline(cin, searchTitle);

                bookstore::Book* foundBook = bookstore.findBook(searchTitle);
                if (foundBook) {
                    cout << "Book found: " << *foundBook << endl;
                } else {
                    cout << "Book not found in inventory." << endl;
                }
                break;
            }
            case 3:
                bookstore.displayInventory();
                break;
            case 4:
                bookstore.displayAddress();
                break;
            case 5:
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        // Display the menu again after processing the choice
        displayMenu();
    }

    return 0;
}

#include<iostream>
#include<conio.h>

using namespace std;

class Book {
public:
    string title;
    string author;
    int bookID;
    int copiesAvailable;
    int totalCopies;
public:
    Book(string t, string author, int bookID, int copiesAvailable, int totalCopies) {
        title = t;
        this->author = author;
        this->bookID = bookID;
        this->copiesAvailable = copiesAvailable;
        this->totalCopies = totalCopies;
    }
};

class Library {
    private :
    Book* books[100]; // Array to hold pointers to Book objects

    public:
    Library() {
        for(int i = 0; i < 100; i++) {
            books[i] = nullptr; // Initialize all book pointers to nullptr
        }
    }
    void addBook(){
        string title, author;
        int bookID, copiesAvailable, totalCopies;
        cin.ignore();
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book ID: ";
        cin>> bookID;
        cout << "Enter number of copies available: ";
        cin >> copiesAvailable;
        cout << "Enter total number of copies: ";
        cin >> totalCopies;
        books[bookID] = new Book(title, author, bookID, copiesAvailable, totalCopies);
    }

    void showBooks() {
    cout << "List of Books in the Library:" << endl;
    bool found = false;
    for (int i = 0; i < 100; i++) {
        if (books[i] != nullptr) {
            cout << "ID: " << books[i]->bookID << " | "
                 << books[i]->title << " by " << books[i]->author
                 << " | Available: " << books[i]->copiesAvailable
                 << "/" << books[i]->totalCopies << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books in the library." << endl;
    }
}

    void searchBook(){
        string title;
        cin.ignore();
        cout << "Enter book title to search: ";
        getline(cin, title);
        for(int i = 0; i < 100; i++){
            if(books[i] != nullptr && books[i]->title == title){
                cout << "Book found: " << books[i]->title << " by " << books[i]->author << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }
    void deleteBook(){
        int bookID;
        cout << "Enter book ID to delete: ";
        cin >> bookID;
        if(books[bookID] != nullptr){
            delete books[bookID];
            books[bookID] = nullptr;
            cout << "Book deleted successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }


};
int main(){
    cout << "Welcome to the Libray System" << endl;
    Library library;
    int choice;
    do {
        cout << "1. Add Book" << endl;
        cout << "2. Show Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
   
            switch(choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.showBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.deleteBook();
                break;
            case 5:
                cout << "Exiting the Library System." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        }
        while(choice != 5);
    getch(); // Wait for a key press before exiting
        
    }
    


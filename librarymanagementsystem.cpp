#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;
};

Book books[100];
int countBooks = 0;

void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> books[countBooks].id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[countBooks].title);

    cout << "Enter Author Name: ";
    getline(cin, books[countBooks].author);

    books[countBooks].issued = false;
    countBooks++;

    cout << "Book Added Successfully!\n";
}

void displayBooks() {
    cout << "\n----- Book List -----\n";

    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << books[i].id
             << "\nTitle: " << books[i].title
             << "\nAuthor: " << books[i].author
             << "\nStatus: "
             << (books[i].issued ? "Issued" : "Available")
             << "\n------------------\n";
    }
}

void searchByTitle() {
    string title;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    bool found = false;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].title == title) {
            cout << "\nBook Found!\n";
            cout << "ID: " << books[i].id
                 << "\nAuthor: " << books[i].author << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book Not Found!\n";
}

void searchByAuthor() {
    string author;
    cin.ignore();

    cout << "Enter Author Name: ";
    getline(cin, author);

    bool found = false;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].author == author) {
            cout << "\nTitle: " << books[i].title
                 << "\nID: " << books[i].id << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No Books Found!\n";
}

void issueBook() {
    int id;

    cout << "Enter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].id == id) {
            if (!books[i].issued) {
                books[i].issued = true;
                cout << "Book Issued Successfully!\n";
            } else {
                cout << "Book Already Issued!\n";
            }
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void returnBook() {
    int id;

    cout << "Enter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (books[i].id == id) {
            if (books[i].issued) {
                books[i].issued = false;
                cout << "Book Returned Successfully!\n";
            } else {
                cout << "Book Was Not Issued!\n";
            }
            return;
        }
    }

    cout << "Book Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchByTitle();
                break;
            case 4:
                searchByAuthor();
                break;
            case 5:
                issueBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}

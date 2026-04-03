

#include <iostream>
using namespace std;

struct Author {
    int id;
    string name;
};

struct Book {
    int id;
    string name;
    Author author;
};

struct Node {
    Book data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

int main()
{
    LinkedList books = { NULL };
    do {
        system("cls");
        cout << "------ BOOK MANAGEMENT ------" << endl;
        cout << "1. Show all books" << endl;
        cout << "2. Add a book" << endl;
        cout << "3. Delete a book" << endl;
        cout << "4. Update a book" << endl;
        cout << "5. Find book" << endl;
        cout << "6. Export to file" << endl;
        cout << "7. Import from file" << endl;
        cout << "o. exit" << endl;
        cout << "---------------------------------" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
        case 7: {
            break;
        }
        case 0: {
            break;
        }
        default: {
            cout << " Invalid choice, try again" << endl;
            break;
        }

        }
    } while (true); 
}




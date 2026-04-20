

#include <iostream>
#include "Account.h"
#include "Linkedlist.h"

int main()
{
    LinkedList <Account> account = { NULL };
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
            Account.Show();
            break;
        }
        case 2: {
            Account a;
            cin >> a;
            account.Add(a);
            break;
        }
        case 3: {
            int removeId;
            cout << "Enter account Id to remove: ";
            cin >> removeId;
            bool res = account.Remove(removeId);
            if (res)
                cout << "Remove account with id:" << removeId << endl;
            else
                cout << "Not found account id: " << removeId << endl;
            break;
        }
        case 4:
        {
            int updateId;
            cout << "Enter account Id to update: ";
            cin >> updateId;
            bool res = account.Update(updateId);
            if (res)
                cout << "Update account with id: " << updateId << endl;
            else
                cout << "Not found account id: " << updateId << endl;
            break;
        }
        case 5: {
            /*string bookName;
            cout << "Enter book's name to find: ";
            cin.ignore();
            getline(cin, bookName);
            Book* res = books.Find(bookName);
            if (res != NULL) {
                cout << *res;
            }
            else {
                cout << "No book with name: " << bookName << endl;
            }*/
            break;
        }
        case 6: {
            /*books.Export("25TH1.dla");
            cout << "Exported successfully" << endl;*/
            break;
        }
        case 7: {
            /*books.Import("25TH1.dla");*/
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
        system("pause");
        cout << "Press any key to continue...";




    } while (true);
}



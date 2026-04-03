

#include <iostream>
#include <string>
using namespace std;

struct Person {
	int id;
	string name;
	friend ostream& operator <<(ostream& os, const Person& p) {
		os << "\t+ Id: " << p.id << endl;
		os << "\t+ Name: " << p.name << endl;
		return os;
	}
	friend istream& operator <<(istream& in, Person& p) {
		cout << "Input person information: " << endl;
		cout << "\t+ Id: ";
		in >> p.id;
		cout << "\t+ Name: ";
		in >> p.name;
		return in;
	}
};

struct Node {
	Person data;
	Node* next;
	Node(Person x) : data(x), next(nullptr) {}
};
struct LinkedList {
	Node* head;
	void Show() {
		if (head == NULL) {
			cout << "Empty list" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			cout << "Id: " << item->data.id << endl;
			cout << "name: " << item->data.name << endl;
			item = item->next;
		}
	}
	void Add(Person x) {
		Node* newNode = new Node(x);
		newNode->next = head;
		head = newNode;
	}
	bool Remove(int x) {
		if (head == NULL) {
			return false;
		}
		Node* item = head;
		if (item->data.id == x) {
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == x) {
				Node* temp = item->next;
				item->next = temp->next;
				delete temp;
				return true;
			}
			item = item->next;
		}
	}
};

int main()
{
	LinkedList list = {NULL};
	do {
		system("cls");
		cout << " ---HUMAN RESOURCE --------" << endl;
		cout << "1. View person list" << endl;
		cout << "2. Add a person" << endl;
		cout << "3. Remove a pearson" << endl;
		cout << "4. Find a person by name" << endl;
		cout << "5. Export to file " << endl;
		cout << "6. Import from file" << endl;
		cout << "0. Exit" << endl;
		cout << "---------------------------" << endl;
		cout << "You command: ";
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1: {
			
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			bool res = list.Remove(id);
			if (res)
				cout << "Remove a person successfully" << endl;
			else
				cout << "Person isn't found" << endl;
			
			break;
		}
		case 4: {
			string name;
			cout << "input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = false;
			if (res)
				cout << "found person with name" << name << endl;
			else
				cout << "person isn't existed" << endl;
			break;
		}
		case 5: {
			cout << "export successfully" << endl;
			break;
		}
		case 6: {
			cout << "import successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		}

		default:
			cout << " Your command isn't found. Try again.." << endl;
			break;
		}
		cout << " Press Enter to continue...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;

}




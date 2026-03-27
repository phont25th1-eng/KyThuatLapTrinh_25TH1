
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Person {
	int id;
	string name;
	int age;
	string address;
};
void ViewPersonList(vector<Person> p) {
	if (p.size() == 0)
		cout << "An empty list" << endl;
	else {
		for (int i = 0; i < p.size(); i++) {
			cout << " Person " << (i + 1) << endl;
			cout << "\t+ Id: " << p[i].id << endl;
			cout << "\t+ Name: " << p[i].name << endl;
			cout << "\t+ Age : " << p[i].age << endl;
			cout <<"\t+ Address: " << p[i].address << endl;
		}
	}
}

void AddPerson(vector<Person>& p) {
	Person a;
	cout << "+ Id: ";
	cin >> a.id;
	cout << "+ Name:";
	cin.ignore();
	getline(cin, a.name);
	cout << "+ Age: ";
	cin >> a.age;
	cout << " + Address:";
	cin.ignore();
	getline(cin, a.address);
	p.push_back(a);
	cout << "Add a pearson successfully" << endl;
}

void RemovePerson(vector<Person>& p, int id) {
	for (auto i = p.begin(); i != p.end(); i++) {
		if (i->id == id) {
			p.erase(i);
			cout << "Remove a person successfully" << endl;
			return;
		}
	}
	cout << "Not found peson with id: " << id << endl;
}
bool FindPerson(vector<Person> p, string fileName) {
	for (Person i : p) {
		if (i.name == name) {
			return true;
	}
	}
	return false;
}
void ExportToFile(vector<Person> p, string fileName) {
	ofstream file(fileName, ios::binary);
	if (!file) {
		cout << "Can't open this file" << endl;
		return;
	}
	for (Person i : p) {
		file.write(reinterpret_cast<const char*>(&i.id), sizeof(i.id));

		size_t namelength = i.name.size();
		file.write(reinterpret_cast<const char*>(&namelength), sizeof(namelength));
		file.write(i.name.c_str(), namelength);
		file.write(reinterpret_cast<const char*>(&i.age), sizeof(i.age));
		size_t addresslength = i.address = i.size();
		file.write(reinterpret_cast<const char*>(&addresslength), sizeof(addresslength));
		file.write(i.address.c_str(), addresslength;
	}

}
void readFromFile(vector<Person>& p, string fileName) {
	ifstream file(fileName, ios::binary);
	if (!file) {
		cout << "Can't open this file" << endl;
		return;
	}
	/*while (p.size()>0)
	 {
	 p.pop_back();
	 }*/
	Person i;
	while (file.peek() != EOF) {
		file.read(reinterpret_cast<char*>(&i.id), sizeof(i.id));
		size_t nameLength;
		file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		i.name.resize(nameLength);
		file.read(&i.name[0], nameLength);
		file.read(reinterpret_cast<char*>(&i.age), sizeof(i.age));
		size_t addressLength;
		file.read(reinterpret_cast<char*>(&addressLength), sizeof(addressLength));
		i.address.resize(addressLength);
		file.read(&i.address[0], addressLength);

		RemovePerson(p, i.id);
		p.push_back(i);

	}
}
int main() {
	vector <Person> list;
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
			ViewPersonList(list);
			break;
		}
		case 2: {
			AddPerson(list);
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			RemovePerson(list, id);
			break;
		}
		case 4: {
			string name;
			cout << "input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = false;
			if (res) {
				cout << "found person with name" << name << endl;
			}
			else
				cout << "person isn't existed" << endl;
			break;
		}
		case 5: {
			ExportToFile(list, "25TH1.dla");
			cout << "Export successfully" << endl;
			break;
		}
		case 6: {
			readFromFile(list, "25TH1.dla");
			cout << "Import successfully" << endl;
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
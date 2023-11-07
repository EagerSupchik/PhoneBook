#pragma once
#include <fstream>
#include <vector>

using namespace std;

class PhoneBook
{
private:
	vector<Contacts> contacts;

public:
	void addContact(const Contacts& contact)
	{
		contacts.push_back(contact);
	}

	void removeContact(const char* name)
	{
		for(auto i = contacts.begin(); i != contacts.end(); i++)
		{
			if (strcmp(i->getname(), name) == 0)
			{
				contacts.erase(i);
				break;
			}
		}
	}

	Contacts* findContact(const char* name)
	{
		for (auto i = contacts.begin(); i != contacts.end(); i++)
		{
			if (strcmp(i->getname(), name) == 0)
			{
				return &(*i);
			}
		}
		return nullptr;
	}

	void printContact() const
	{
		for (const auto& contact : contacts)
		{
			cout << "Name: " << contact.getname() << endl;
			cout << "DT: " << contact.gethp() << endl;
			cout << "WT: " << contact.getwp() << endl;
			cout << "MT: " << contact.getmp() << endl;
			cout << "ADDS: " << contact.getadds() << endl;
		}
	}

	void save(const char* filename) const
	{
		ofstream file(filename);
		if (file.is_open())
		{
			for (const auto& contact : contacts)
			{
				file << contact.getname() << endl;
				file << contact.gethp() << endl;
				file << contact.getwp() << endl;
				file << contact.getmp() << endl;
				file << contact.getadds() << endl;
			}
		}
		file.close();
	}

	void load(const char* filename)
	{
		ifstream file(filename);
		if (file.is_open())
		{
			contacts.clear();

			char name[255];
			int home, work, mobile;
			char adds[255];

			while (file.getline(name, 255))
			{
				file >> home >> work >> mobile;
				file.ignore();
				file.getline(adds, 255);

				Contacts contact(name, home, work, mobile, adds);
				contacts.push_back(contact);
			}
		}
		file.close();
	}
};




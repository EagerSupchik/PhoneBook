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
				//return &(*i);
				cout << "Name: " << i->getname() << endl;
				cout << "HP: " << i->gethp() << endl;
				cout << "WP: " << i->getwp() << endl;
				cout << "MP: " << i->getmp() << endl;
				cout << "ADDS:" << i->getadds() << endl;
			}
		}
		return nullptr;
	}

	void printContact() const
	{
		for (const auto& contact : contacts)
		{
			cout << "ФИО: " << contact.getname() << endl;
			cout << "Домашний телефон: " << contact.gethp() << endl;
			cout << "Рабочий телефон: " << contact.getwp() << endl;
			cout << "Мобильный телефон: " << contact.getmp() << endl;
			cout << "Доп. информация: " << contact.getadds() << endl;
			cout << endl;
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

			char name[250];
			int home, work, mobile;
			char adds[250];

			while (file.getline(name, 250))
			{
				file >> home >> work >> mobile;
				file.ignore();
				file.getline(adds, 250);

				Contacts contact(name, home, work, mobile, adds);
				contacts.push_back(contact);
			}
		}
		file.close();
	}

	void del()
	{
		contacts.clear();
	}
};




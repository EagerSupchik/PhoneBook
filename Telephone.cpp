#include <iostream>
#include "Contacts.h"
#include "phoneBook.h"
#include <Windows.h>

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    PhoneBook pb;
    pb.addContact(Contacts("XD vw ggg", 1234567, 756332, 343546, "XSSSSS"));

    pb.printContact();

    Contacts* contact = pb.findContact("XD vw ggg");
    if (contact != nullptr)
    {
        cout << contact->getname() << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    pb.save("phonebook.txt");


}

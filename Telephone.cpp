#include <iostream>
#include "Contacts.h"
#include "phoneBook.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook pb;
    int c;

    while (true)
    {
        cout << R"(
-----Телефонная книга-----
1. Добавить контакт
2. Удалить контакт
3. Вывести все контакты на экран
4. Найти контакт
5. Загрузить контакты в файл
6. Перезаписать контакты
0. Выход
)";

        cin >> c;
        system("cls");
        switch (c)
        {
        case 1:
            char name[250], adds[250];
            int hp, wp, mp;

            cout << "Введите имя контакта: ";
            cin >> name;
            cout << "Введите домашний номер телефона: ";
            cin >> hp;
            cout << "Введите рабочий номер телефона: ";
            cin >> wp;
            cout << "Введите мобильный номер телефона: ";
            cin >> mp;
            cout << "Введите дополнительную информацию: ";
            cin >> adds;

            pb.addContact(Contacts(name, hp, wp, mp, adds));
            break;

        case 2:
            cout << "Введите имя удаляемого контакта: ";
            cin >> name;
            pb.removeContact(name);
            cout << "Готово!";
            break;

        case 3:
            pb.printContact();
            break;

        case 4:
            cout << "Введите имя контакта: ";
            cin >> name;
            pb.findContact(name);
            break;

        case 5:
            pb.save("phonebook.txt");
            break;

        case 6:
            pb.load("phonebook.txt");
            break;

        default:
            pb.del();
            exit(0);
            break;
        }
    }
    pb.del();
}

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class FATHER {
protected:
    string name;

public:
    // конструктор базового класу FATHER
    FATHER(const string& name) : name(name) {}

    // віртуальна функція для вводу імені
    virtual void enterName() {
        cout << "Введіть ім'я батька: ";
        cin >> name;
    }
    // віртуальна функція для виводу імені
    virtual void printName() {
        cout << "Ім'я батька: " << name << endl;
    }
};

class CHILD : public FATHER {
public:
    //конструктор похідного класу CHILD
    CHILD(const string& name, const string& parentName)
        : FATHER(name), parentName(parentName) {}

    // Перевизначення віртуальної функції з базового класу
    void enterName() override {
        cout << "Введіть ім'я первістка: ";
        cin >> name;
    }
    // Перевизначення віртуальної функції з базового класу
    void printName() override {
        char lastChar = parentName.back();
        string ending;

        if (lastChar == 'і' || lastChar == 'ї') {
            ending = "івич";
        }
        else {
            ending = "ович";
        }

        cout << "Ім'я дитини: " << name << " " << parentName << ending << endl;
    }

private:
    string parentName;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string parentName, childName;

    cout << "Введіть ім'я батька: ";
    cin >> parentName;

    FATHER parent(parentName);
    CHILD child("", parentName);

    child.enterName();

    child.printName();

    return 0;
}

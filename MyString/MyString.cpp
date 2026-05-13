#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* str;
    char* updatedStr;
    int length;

public:
    MyString();
    MyString(const char* text);
    MyString(const MyString& other);
    ~MyString();

    void set(const char* text);
    void update();
    void print() const;
};

MyString::MyString() {
    cout << "Вызван конструктор без параметров" << endl;

    length = 0;
    str = new char[1];
    str[0] = '\0';

    updatedStr = new char[1];
    updatedStr[0] = '\0';
}

MyString::MyString(const char* text) {
    cout << "Вызван конструктор с параметрами" << endl;

    length = strlen(text);

    str = new char[length + 1];
    strcpy_s(str, length + 1, text);

    updatedStr = new char[length + 1];
    strcpy_s(updatedStr, length + 1, text);
}

MyString::MyString(const MyString& other) {
    cout << "Вызван конструктор копирования" << endl;

    length = other.length;

    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str);

    updatedStr = new char[strlen(other.updatedStr) + 1];
    strcpy_s(updatedStr, strlen(other.updatedStr) + 1, other.updatedStr);
}

MyString::~MyString() {
    cout << "Вызван деструктор" << endl;

    delete[] str;
    delete[] updatedStr;
}

void MyString::set(const char* text) {
    cout << "Вызван метод set()" << endl;

    delete[] str;
    delete[] updatedStr;

    length = strlen(text);

    str = new char[length + 1];
    strcpy_s(str, length + 1, text);

    updatedStr = new char[length + 1];
    strcpy_s(updatedStr, length + 1, text);
}

void MyString::update() {
    cout << "Вызван метод update()" << endl;

    if (length % 2 == 0 && length >= 4) {
        int newLength = length - 4;

        delete[] updatedStr;
        updatedStr = new char[newLength + 1];

        for (int i = 0; i < newLength; i++) {
            updatedStr[i] = str[i + 2];
        }

        updatedStr[newLength] = '\0';
    }
    else {
        cout << "Условие не выполнено: длина строки должна быть четной и не меньше 4." << endl;
    }

    ofstream file("result.txt");

    if (file.is_open()) {
        file << "Исходная строка: " << str << endl;
        file << "Измененная строка:" << updatedStr << endl;
        file.close();

        cout << "Данные сохранены в файл result.txt" << endl;
    }
    else {
        cout << "Ошибка открытия файла." << endl;
    }
}

void MyString::print() const {
    cout << "Вызван метод print()" << endl;

    cout << "Исходная строка: " << str << endl;
    cout << "Измененная строка: " << updatedStr << endl;
    cout << "Длина строки: " << length << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Создание объекта string1" << endl;
    MyString string1("HelloWorld");

    cout << endl;
    string1.print();

    cout << endl;
    string1.update();

    cout << endl;
    string1.print();

    cout << endl << "Изменение строки через метод set()" << endl;
    string1.set("Programming");

    cout << endl;
    string1.print();

    cout << endl;
    string1.update();

    cout << endl;
    string1.print();

    cout << endl << "Создание объекта string2 через конструктор копирования" << endl;
    MyString string2 = string1;

    cout << endl;
    string2.print();

    cin.get();

    return 0;
}
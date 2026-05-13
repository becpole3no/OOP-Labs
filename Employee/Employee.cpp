#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string fullName;
    int age;
    int experience;

public:
    Employee();
    Employee(string name, int employeeAge, int employeeExperience);
    Employee(const Employee& other);
    virtual ~Employee();

    void printEmployeeInfo() const;
};

class Director : public Employee {
protected:
    string education;
    string managementLevel;

public:
    Director();
    Director(string name, int employeeAge, int employeeExperience,
        string directorEducation, string level);
    Director(const Director& other);
    virtual ~Director();

    void printDirectorInfo() const;
};

class Firm {
protected:
    string firmName;
    string address;
    int employeeCount;

public:
    Firm();
    Firm(string name, string firmAddress, int count);
    Firm(const Firm& other);
    virtual ~Firm();

    void printFirmInfo() const;
};

class FirmManager : public Director, public Firm {
protected:
    string position;

public:
    FirmManager();
    FirmManager(string name, int employeeAge, int employeeExperience,
        string directorEducation, string level,
        string firmName, string firmAddress, int count,
        string managerPosition);
    FirmManager(const FirmManager& other);
    virtual ~FirmManager();

    virtual void printInfo() const;
};

class StateInstitutionManager : public FirmManager {
private:
    string institutionType;
    string fundingSource;

public:
    StateInstitutionManager();
    StateInstitutionManager(string name, int employeeAge, int employeeExperience,
        string directorEducation, string level,
        string firmName, string firmAddress, int count,
        string managerPosition,
        string type, string source);
    StateInstitutionManager(const StateInstitutionManager& other);
    ~StateInstitutionManager();

    void printInfo() const override;
};

class LLCManager : public FirmManager {
private:
    string ownershipForm;
    double authorizedCapital;

public:
    LLCManager();
    LLCManager(string name, int employeeAge, int employeeExperience,
        string directorEducation, string level,
        string firmName, string firmAddress, int count,
        string managerPosition,
        string form, double capital);
    LLCManager(const LLCManager& other);
    ~LLCManager();

    void printInfo() const override;
};

Employee::Employee() {
    cout << "Вызван конструктор Employee без параметров" << endl;
    fullName = "Не указано";
    age = 0;
    experience = 0;
}

Employee::Employee(string name, int employeeAge, int employeeExperience) {
    cout << "Вызван конструктор Employee с параметрами" << endl;
    fullName = name;
    age = employeeAge;
    experience = employeeExperience;
}

Employee::Employee(const Employee& other) {
    cout << "Вызван конструктор копирования Employee" << endl;
    fullName = other.fullName;
    age = other.age;
    experience = other.experience;
}

Employee::~Employee() {
    cout << "Вызван деструктор Employee" << endl;
}

void Employee::printEmployeeInfo() const {
    cout << "ФИО служащего: " << fullName << endl;
    cout << "Возраст: " << age << endl;
    cout << "Стаж работы: " << experience << " лет" << endl;
}

Director::Director() : Employee() {
    cout << "Вызван конструктор Director без параметров" << endl;
    education = "Не указано";
    managementLevel = "Не указано";
}

Director::Director(string name, int employeeAge, int employeeExperience,
    string directorEducation, string level)
    : Employee(name, employeeAge, employeeExperience) {
    cout << "Вызван конструктор Director с параметрами" << endl;
    education = directorEducation;
    managementLevel = level;
}

Director::Director(const Director& other) : Employee(other) {
    cout << "Вызван конструктор копирования Director" << endl;
    education = other.education;
    managementLevel = other.managementLevel;
}

Director::~Director() {
    cout << "Вызван деструктор Director" << endl;
}

void Director::printDirectorInfo() const {
    printEmployeeInfo();
    cout << "Образование: " << education << endl;
    cout << "Уровень управления: " << managementLevel << endl;
}

Firm::Firm() {
    cout << "Вызван конструктор Firm без параметров" << endl;
    firmName = "Не указано";
    address = "Не указано";
    employeeCount = 0;
}

Firm::Firm(string name, string firmAddress, int count) {
    cout << "Вызван конструктор Firm с параметрами" << endl;
    firmName = name;
    address = firmAddress;
    employeeCount = count;
}

Firm::Firm(const Firm& other) {
    cout << "Вызван конструктор копирования Firm" << endl;
    firmName = other.firmName;
    address = other.address;
    employeeCount = other.employeeCount;
}

Firm::~Firm() {
    cout << "Вызван деструктор Firm" << endl;
}

void Firm::printFirmInfo() const {
    cout << "Название фирмы: " << firmName << endl;
    cout << "Адрес: " << address << endl;
    cout << "Количество сотрудников: " << employeeCount << endl;
}

FirmManager::FirmManager() : Director(), Firm() {
    cout << "Вызван конструктор FirmManager без параметров" << endl;
    position = "Руководитель фирмы";
}

FirmManager::FirmManager(string name, int employeeAge, int employeeExperience,
    string directorEducation, string level,
    string firmName, string firmAddress, int count,
    string managerPosition)
    : Director(name, employeeAge, employeeExperience, directorEducation, level),
    Firm(firmName, firmAddress, count) {
    cout << "Вызван конструктор FirmManager с параметрами" << endl;
    position = managerPosition;
}

FirmManager::FirmManager(const FirmManager& other)
    : Director(other), Firm(other) {
    cout << "Вызван конструктор копирования FirmManager" << endl;
    position = other.position;
}

FirmManager::~FirmManager() {
    cout << "Вызван деструктор FirmManager" << endl;
}

void FirmManager::printInfo() const {
    cout << "Информация о руководителе фирмы" << endl;
    cout << "Должность: " << position << endl;
    printDirectorInfo();
    printFirmInfo();
}

StateInstitutionManager::StateInstitutionManager() : FirmManager() {
    cout << "Вызван конструктор StateInstitutionManager без параметров" << endl;
    institutionType = "Государственное учреждение";
    fundingSource = "Бюджет";
}

StateInstitutionManager::StateInstitutionManager(string name, int employeeAge, int employeeExperience,
    string directorEducation, string level,
    string firmName, string firmAddress, int count,
    string managerPosition,
    string type, string source)
    : FirmManager(name, employeeAge, employeeExperience,
        directorEducation, level,
        firmName, firmAddress, count,
        managerPosition) {
    cout << "Вызван конструктор StateInstitutionManager с параметрами" << endl;
    institutionType = type;
    fundingSource = source;
}

StateInstitutionManager::StateInstitutionManager(const StateInstitutionManager& other)
    : FirmManager(other) {
    cout << "Вызван конструктор копирования StateInstitutionManager" << endl;
    institutionType = other.institutionType;
    fundingSource = other.fundingSource;
}

StateInstitutionManager::~StateInstitutionManager() {
    cout << "Вызван деструктор StateInstitutionManager" << endl;
}

void StateInstitutionManager::printInfo() const {
    cout << "Руководитель государственного учреждения" << endl;
    FirmManager::printInfo();
    cout << "Тип учреждения: " << institutionType << endl;
    cout << "Источник финансирования: " << fundingSource << endl;
}

LLCManager::LLCManager() : FirmManager() {
    cout << "Вызван конструктор LLCManager без параметров" << endl;
    ownershipForm = "ООО";
    authorizedCapital = 0;
}

LLCManager::LLCManager(string name, int employeeAge, int employeeExperience,
    string directorEducation, string level,
    string firmName, string firmAddress, int count,
    string managerPosition,
    string form, double capital)
    : FirmManager(name, employeeAge, employeeExperience,
        directorEducation, level,
        firmName, firmAddress, count,
        managerPosition) {
    cout << "Вызван конструктор LLCManager с параметрами" << endl;
    ownershipForm = form;
    authorizedCapital = capital;
}

LLCManager::LLCManager(const LLCManager& other)
    : FirmManager(other) {
    cout << "Вызван конструктор копирования LLCManager" << endl;
    ownershipForm = other.ownershipForm;
    authorizedCapital = other.authorizedCapital;
}

LLCManager::~LLCManager() {
    cout << "Вызван деструктор LLCManager" << endl;
}

void LLCManager::printInfo() const {
    cout << "Руководитель общества с ограниченной ответственностью" << endl;
    FirmManager::printInfo();
    cout << "Форма собственности: " << ownershipForm << endl;
    cout << "Уставный капитал: " << authorizedCapital << " руб." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << fixed;
    cout.precision(2);

    cout << "Создание руководителя государственного учреждения" << endl;
    StateInstitutionManager stateManager(
        "Иванов Иван Иванович", 45, 20,
        "Высшее экономическое", "Высший уровень",
        "Тольяттинский государственный университет", "г. Тольятти, ул. Белорусская, 14", 1200,
        "Ректор",
        "Государственное образовательное учреждение", "Федеральный бюджет"
    );

    cout << endl;
    stateManager.printInfo();

    cout << endl << "Создание руководителя ООО" << endl;
    LLCManager llcManager(
        "Петров Петр Петрович", 38, 15,
        "Высшее юридическое", "Высший уровень",
        "ООО ВолгаТех", "г. Тольятти, ул. Революционная, 52", 55,
        "Генеральный директор",
        "Общество с ограниченной ответственностью", 1000000
    );

    cout << endl;
    llcManager.printInfo();

    cout << endl << "Проверка конструктора копирования" << endl;
    LLCManager copyManager = llcManager;

    cout << endl;
    copyManager.printInfo();

    cin.get();

    return 0;
}
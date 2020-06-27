#include <iostream> // Библиотека ввода/вывода консоли

class TelephoneDirectory // Базовый абстрактный класс
{
public:
    virtual void printEntry() = 0; // виртуальная функция завершается значением =0
    virtual bool isEntry(std::string lastName) = 0;
};

/// <summary>
/// Класс Persona. Производный от TelephoneDirectory
/// </summary>
class Persona : public TelephoneDirectory
{
private:
    std::string _lastName, _address, _phoneNumber;

public:
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="lastName">Фамилия</param>
    /// <param name="address">Адрес</param>
    /// <param name="phoneNumber">Номер телефона</param>
    /// <returns>Ссылку на экземпляр созданного объекта</returns>
    Persona(std::string lastName, std::string address, std::string phoneNumber) : _lastName(lastName), _address(address), _phoneNumber(phoneNumber)
    {
    }

    /// <summary>
    /// Проверяет запись на соответствие параметру поиска (фамилия человека)
    /// </summary>
    /// <param name="name">Фамилия человека</param>
    /// <returns>true, в случае соответствия записи параметру поиска</returns>
    bool isEntry(std::string lastName) override
    {
        return (_lastName == lastName) ? true : false;
    }

    /// <summary>
    /// Выводит запись на консоль
    /// </summary>
    void printEntry() override
    {
        std::cout << _lastName + " " + _address + " " + _phoneNumber << std::endl;
    }
};

/// <summary>
/// Класс Organization. Производный от TelephoneDirectory
/// </summary>
class Organization : public TelephoneDirectory
{
private:
    std::string _name, _address, _phoneNumber, _fax, _contactPerson;
public:
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="name">Название</param>
    /// <param name="address">Адрес</param>
    /// <param name="phoneNumber">Номер телефона</param>
    /// <param name="fax">Факс</param>
    /// <param name="contactPerson">Контактное лицо</param>
    /// <returns>Ссылку на экземляр объекта</returns>
    Organization(std::string name, std::string address, std::string phoneNumber, std::string fax, std::string contactPerson) 
        : _name(name), _address(address), _phoneNumber(phoneNumber), _fax(fax), _contactPerson(contactPerson)
    {
    }

    /// <summary>
    /// Проверяет запись на соответствие параметру поиска (название организации)
    /// </summary>
    /// <param name="name">Название организации</param>
    /// <returns>true, в случае соответствия записи параметру поиска</returns>
    bool isEntry(std::string name) override
    {
        return (_name == name) ? true : false;
    }

    /// <summary>
    /// Выводит запись на консоль
    /// </summary>
    void printEntry() override
    {
        std::cout << _name + " " + _address + " " + _phoneNumber + " " + _fax + " " + _contactPerson << std::endl;
    }
};

/// <summary>
/// Класс Friend. Производный от TelephoneDirectory
/// </summary>
class Friend : public TelephoneDirectory
{
private:
    std::string _lastName, _address, _phoneNumber, _dateOfBirth;

public:
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="lastName">Фамилия</param>
    /// <param name="address">Адрес</param>
    /// <param name="phoneNumber">Номер телефона</param>
    /// <param name="dateOfBirth">Дата рождения</param>
    /// <returns>Ссылку на экземпляр созданного объекта</returns>
    Friend(std::string lastName, std::string address, std::string phoneNumber, std::string dateOfBirth) 
        : _lastName(lastName), _address(address), _phoneNumber(phoneNumber), _dateOfBirth(dateOfBirth)
    {
    }

    /// <summary>
    /// Проверяет запись на соответствие параметру поиска (фамилия друга)
    /// </summary>
    /// <param name="name">Фамилия друга</param>
    /// <returns>true, в случае соответствия записи параметру поиска</returns>
    bool isEntry(std::string lastName) override
    {
        return (_lastName == lastName) ? true : false;
    }

    /// <summary>
    /// Выводит запись на консоль
    /// </summary>
    void printEntry() override
    {
        std::cout << _lastName + " " + _address + " " + _phoneNumber + " " + _dateOfBirth << std::endl;
    }
};

TelephoneDirectory** a = NULL;   // указатель на TelephoneDirectory пока что инициализированный нуллом,
                                // что бы потом пользователь сам ввел размерность массива
int counter = 0; // счётчик записей
int max = 0; // максимальное число элементов массива

/// <summary>
/// Функция создания новой записи
/// </summary>
/// <param name="entryType">Тип записи</param>
void newEntry(int entryType) {
    std::string name, address, lastName, phoneNumber, fax, contactPersont, dateOfBirth;
    switch (entryType)
    {
    case 1:
        std::cout << "Enter last name: ";
        std::cin >> lastName;
        std::cout << "Enter address: ";
        std::cin >> address;
        std::cout << "Enter phoneNumber: ";
        std::cin >> phoneNumber;
        a[counter++] = new Persona(lastName, address, phoneNumber);
        break;
    case 2:
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter address: ";
        std::cin >> address;
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        std::cout << "Enter fax: ";
        std::cin >> fax;
        std::cout << "Enter contact person: ";
        std::cin >> contactPersont;
        a[counter++] = new Organization(name, address, phoneNumber, fax, contactPersont);
        break;
    case 3:
        std::cout << "Enter last name: ";
        std::cin >> lastName;
        std::cout << "Enter address: ";
        std::cin >> address;
        std::cout << "Enter phoneNumber: ";
        std::cin >> phoneNumber;
        std::cout << "Enter date of birth: ";
        std::cin >> dateOfBirth;
        a[counter++] = new Friend(lastName, address, phoneNumber, dateOfBirth);
        break;
    default:
        break;
    }
}

/// <summary>
/// Функция поиска записи
/// </summary>
/// <param name="searchParam">Параметри поиска</param>
void searchEntry(std::string searchParam) {
    std::cout << "Search results: \n";
    bool found = false; // Флаг результата поиска
    for (size_t i = 0; i < counter; i++)
    {
        if (a[i]->isEntry(searchParam)) {
            found = true;
            a[i]->printEntry();
            // Так как людей с одной фамилией может быть несколько продолжаем поиск
        }
    }
    if(!found)
        std::cout << "The entry has not been found\n";
}

/// <summary>
/// Функция вывода всех записей
/// </summary>
void printAll() {
    std::cout << counter + " entries found: \n";
    for (size_t i = 0; i < counter; i++)
    {
        a[i]->printEntry();
    }
}

/// <summary>
/// Функция получения команды пользователя
/// </summary>
/// <returns></returns>
int getCommand() 
{
    int command;
    int entryType; // Тип записи (Персона, Организация или Друг)
    std::string searchParam; // Параметр поиска

    std::cout << "\n"; // Делаем отступ, что бы не создавать беспорядок :)

    if (counter == 0) { // Если записей ещё нет, команды поиска и вывода списка нам не нужны :)
        std::cout << "Commands: 1 - new Persona, 2 - new Organization, 3 - new friend\n";
        std::cout << "Enter your command: ";
        std::cin >> entryType;
        newEntry(entryType);
        return 1;
    }
    if (counter < max) { // Если ещё есть место куда записывать
        std::cout << "Commands: 1 - new entry, 2 - find an entry, 3 - print all, 0 - exit\n";
    }
    else { // если места в книге уже нет :)
        std::cout << "Commands: 2 - find an entry, 3 - print all, 0 - exit\n";
    }
    
    std::cout << "Enter your command: ";

    std::cin >> command;
    switch (command)
    {
    case 1:
        if (counter < max){ // делаем проверку на свободное место ещё раз, вдруг нам попался шалунишка :)
            std::cout << "Commands: 1 - new Persona, 2 - new Organization, 3 - new friend\n";
            std::cout << "Enter your command: ";
            std::cin >> entryType;
            newEntry(entryType);
        }
        else {
            std::cout << "There is no space for a new entry\n";
        }
        break;
    case 2:
        std::cout << "Enter search parameter: ";
        std::cin >> searchParam;
        searchEntry(searchParam);
        break;
    case 3:
        printAll();
        break;
    default:
        break;
    }
    return command;
}

/// <summary>
/// Главная функция программы
/// </summary>
/// <returns>0, если всё закончилось хорошо и 1 если что-то пошло не так</returns>
int main()
{
    int n; // размерность массива (максимальное кол-во записей в нашей телефонной книге

    std::cout << "Enter PhoneBook size: ";
    std::cin >> n;
    a = new TelephoneDirectory*[n];
    max = n;
    bool goNext; // флаг продолжения выполнения программы. Если пользователь введёт команду 0 она будет интерпритирована как false, иначе - true
    do {
        goNext = getCommand();
    } while (goNext);
}
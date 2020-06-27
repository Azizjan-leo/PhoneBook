#include <iostream> // ���������� �����/������ �������

class TelephoneDirectory // ������� ����������� �����
{
public:
    virtual void printEntry() = 0; // ����������� ������� ����������� ��������� =0
    virtual bool isEntry(std::string lastName) = 0;
};

/// <summary>
/// ����� Persona. ����������� �� TelephoneDirectory
/// </summary>
class Persona : public TelephoneDirectory
{
private:
    std::string _lastName, _address, _phoneNumber;

public:
    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="lastName">�������</param>
    /// <param name="address">�����</param>
    /// <param name="phoneNumber">����� ��������</param>
    /// <returns>������ �� ��������� ���������� �������</returns>
    Persona(std::string lastName, std::string address, std::string phoneNumber) : _lastName(lastName), _address(address), _phoneNumber(phoneNumber)
    {
    }

    /// <summary>
    /// ��������� ������ �� ������������ ��������� ������ (������� ��������)
    /// </summary>
    /// <param name="name">������� ��������</param>
    /// <returns>true, � ������ ������������ ������ ��������� ������</returns>
    bool isEntry(std::string lastName) override
    {
        return (_lastName == lastName) ? true : false;
    }

    /// <summary>
    /// ������� ������ �� �������
    /// </summary>
    void printEntry() override
    {
        std::cout << _lastName + " " + _address + " " + _phoneNumber << std::endl;
    }
};

/// <summary>
/// ����� Organization. ����������� �� TelephoneDirectory
/// </summary>
class Organization : public TelephoneDirectory
{
private:
    std::string _name, _address, _phoneNumber, _fax, _contactPerson;
public:
    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="name">��������</param>
    /// <param name="address">�����</param>
    /// <param name="phoneNumber">����� ��������</param>
    /// <param name="fax">����</param>
    /// <param name="contactPerson">���������� ����</param>
    /// <returns>������ �� �������� �������</returns>
    Organization(std::string name, std::string address, std::string phoneNumber, std::string fax, std::string contactPerson) 
        : _name(name), _address(address), _phoneNumber(phoneNumber), _fax(fax), _contactPerson(contactPerson)
    {
    }

    /// <summary>
    /// ��������� ������ �� ������������ ��������� ������ (�������� �����������)
    /// </summary>
    /// <param name="name">�������� �����������</param>
    /// <returns>true, � ������ ������������ ������ ��������� ������</returns>
    bool isEntry(std::string name) override
    {
        return (_name == name) ? true : false;
    }

    /// <summary>
    /// ������� ������ �� �������
    /// </summary>
    void printEntry() override
    {
        std::cout << _name + " " + _address + " " + _phoneNumber + " " + _fax + " " + _contactPerson << std::endl;
    }
};

/// <summary>
/// ����� Friend. ����������� �� TelephoneDirectory
/// </summary>
class Friend : public TelephoneDirectory
{
private:
    std::string _lastName, _address, _phoneNumber, _dateOfBirth;

public:
    /// <summary>
    /// �����������
    /// </summary>
    /// <param name="lastName">�������</param>
    /// <param name="address">�����</param>
    /// <param name="phoneNumber">����� ��������</param>
    /// <param name="dateOfBirth">���� ��������</param>
    /// <returns>������ �� ��������� ���������� �������</returns>
    Friend(std::string lastName, std::string address, std::string phoneNumber, std::string dateOfBirth) 
        : _lastName(lastName), _address(address), _phoneNumber(phoneNumber), _dateOfBirth(dateOfBirth)
    {
    }

    /// <summary>
    /// ��������� ������ �� ������������ ��������� ������ (������� �����)
    /// </summary>
    /// <param name="name">������� �����</param>
    /// <returns>true, � ������ ������������ ������ ��������� ������</returns>
    bool isEntry(std::string lastName) override
    {
        return (_lastName == lastName) ? true : false;
    }

    /// <summary>
    /// ������� ������ �� �������
    /// </summary>
    void printEntry() override
    {
        std::cout << _lastName + " " + _address + " " + _phoneNumber + " " + _dateOfBirth << std::endl;
    }
};

TelephoneDirectory** a = NULL;   // ��������� �� TelephoneDirectory ���� ��� ������������������ ������,
                                // ��� �� ����� ������������ ��� ���� ����������� �������
int counter = 0; // ������� �������
int max = 0; // ������������ ����� ��������� �������

/// <summary>
/// ������� �������� ����� ������
/// </summary>
/// <param name="entryType">��� ������</param>
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
/// ������� ������ ������
/// </summary>
/// <param name="searchParam">��������� ������</param>
void searchEntry(std::string searchParam) {
    std::cout << "Search results: \n";
    bool found = false; // ���� ���������� ������
    for (size_t i = 0; i < counter; i++)
    {
        if (a[i]->isEntry(searchParam)) {
            found = true;
            a[i]->printEntry();
            // ��� ��� ����� � ����� �������� ����� ���� ��������� ���������� �����
        }
    }
    if(!found)
        std::cout << "The entry has not been found\n";
}

/// <summary>
/// ������� ������ ���� �������
/// </summary>
void printAll() {
    std::cout << counter + " entries found: \n";
    for (size_t i = 0; i < counter; i++)
    {
        a[i]->printEntry();
    }
}

/// <summary>
/// ������� ��������� ������� ������������
/// </summary>
/// <returns></returns>
int getCommand() 
{
    int command;
    int entryType; // ��� ������ (�������, ����������� ��� ����)
    std::string searchParam; // �������� ������

    std::cout << "\n"; // ������ ������, ��� �� �� ��������� ���������� :)

    if (counter == 0) { // ���� ������� ��� ���, ������� ������ � ������ ������ ��� �� ����� :)
        std::cout << "Commands: 1 - new Persona, 2 - new Organization, 3 - new friend\n";
        std::cout << "Enter your command: ";
        std::cin >> entryType;
        newEntry(entryType);
        return 1;
    }
    if (counter < max) { // ���� ��� ���� ����� ���� ����������
        std::cout << "Commands: 1 - new entry, 2 - find an entry, 3 - print all, 0 - exit\n";
    }
    else { // ���� ����� � ����� ��� ��� :)
        std::cout << "Commands: 2 - find an entry, 3 - print all, 0 - exit\n";
    }
    
    std::cout << "Enter your command: ";

    std::cin >> command;
    switch (command)
    {
    case 1:
        if (counter < max){ // ������ �������� �� ��������� ����� ��� ���, ����� ��� ������� ��������� :)
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
/// ������� ������� ���������
/// </summary>
/// <returns>0, ���� �� ����������� ������ � 1 ���� ���-�� ����� �� ���</returns>
int main()
{
    int n; // ����������� ������� (������������ ���-�� ������� � ����� ���������� �����

    std::cout << "Enter PhoneBook size: ";
    std::cin >> n;
    a = new TelephoneDirectory*[n];
    max = n;
    bool goNext; // ���� ����������� ���������� ���������. ���� ������������ ����� ������� 0 ��� ����� ���������������� ��� false, ����� - true
    do {
        goNext = getCommand();
    } while (goNext);
}
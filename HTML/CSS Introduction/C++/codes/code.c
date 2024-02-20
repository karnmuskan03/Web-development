#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Phone {
private:
    string stdCode;
    string exchangeCode;
    string phoneNumber;

public:
    Phone(string stdCode, string exchangeCode, string phoneNumber) {
        this->stdCode = stdCode;
        this->exchangeCode = exchangeCode;
        this->phoneNumber = phoneNumber;
    }

    void modifyPhoneNumber() {
        // Add 1 to 1st digit of STD code
        if (stdCode[0] == '9')
            stdCode[0] = '1';
        else
            stdCode[0] += 1;

        // Reverse the first two digits in the phone number
        phoneNumber[0] = stdCode[0];
        phoneNumber[1] = stdCode[1];

        // Display the modified phone number
        cout << stdCode << "-" << exchangeCode << "-" << phoneNumber << endl;
    }
};

int main() {
    vector<Phone> phones;
    int n;

    cout << "Enter the number of phone numbers to modify (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Number of phone numbers exceeds limit." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string stdCode, exchangeCode, phoneNumber;
        cout << "Enter STD code, Exchange code, and Phone number for phone " << i + 1 << ": ";
        cin >> stdCode >> exchangeCode >> phoneNumber;

        Phone phone(stdCode, exchangeCode, phoneNumber);
        phones.push_back(phone);
    }

    cout << "Modified phone numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Modified phone number for phone " << i + 1 << ": ";
        phones[i].modifyPhoneNumber();
    }

    return 0;
}
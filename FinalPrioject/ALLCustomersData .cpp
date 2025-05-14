#include "AllCustomersData .h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;

//this is for reading in the data in the Orginal files
void customerData::read_all_data()
{
    ifstream fin("CustomerData.txt");
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

 
    string name, accountNum, street, city, state, zip, phone;
    readIn = 0;
    while (getline(fin, accountNum)) {
        if (accountNum.empty()) {
            continue;
        }
        set_accountNumber(accountNum);  // Set account number

        // Read name (first and last)
        getline(fin, name);
        set_name(name);

        // Read address details
        getline(fin, street);
        getline(fin, city);
        getline(fin, state);
        set_area(street, city, state);

        // Read zip code and phone number
        getline(fin, zip);
        getline(fin, phone);
        set_codeANDnumber(zip, phone);

       
        readIn++;
    }

    fin.close();
}

//for the output data files
void customerData::readCustomOutData()
{
    ifstream fin("CustomerDataOutPut.txt");
    string name, accountNum, street, city, state, zip, phone;
    readIn = 0;
    while (getline(fin, accountNum)) {
        if (accountNum.empty()) {
            continue;
        }
        set_accountNumber(accountNum);  // Set account number

        // Read name (first and last)
        getline(fin, name);
        set_name(name);

        // Read address details
        getline(fin, street);
        getline(fin, city);
        getline(fin, state);
        set_area(street, city, state);

        // Read zip code and phone number
        getline(fin, zip);
        getline(fin, phone);
        set_codeANDnumber(zip, phone);


        readIn++;
    }


}
//used for deleting the data in the orginal data
void customerData::writeToInFile() {
    ofstream outFile("CustomerData.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < accountNumber.size(); ++i) {
        outFile << accountNumber[i] << endl;
        outFile << fullName[i] << endl;
        outFile << streetAddress[i] << endl;
        outFile << city[i] << endl;
        outFile << state[i] << endl;
        outFile << zipCode[i] << endl;
        outFile << phoneNumber[i] << endl << endl;
    }

    outFile.close();
}
void customerData::deleteCustomerByAccount(string accountNumToDelete) {
    for (int i = 0; i < accountNumber.size();) {
        if (accountNumber[i] == accountNumToDelete) {
            fullName.erase(fullName.begin() + i);
            accountNumber.erase(accountNumber.begin() + i);
            streetAddress.erase(streetAddress.begin() + i);
            city.erase(city.begin() + i);
            state.erase(state.begin() + i);
            zipCode.erase(zipCode.begin() + i);
            phoneNumber.erase(phoneNumber.begin() + i);
        }
        else {
            ++i;
        }
    }
    writeToInFile();

}

void customerData::deleteCustomerByAccountOutFile(string accountNumToDelete) {
    for (int i = 0; i < accountNumber.size();) {
        if (accountNumber[i] == accountNumToDelete) {
            fullName.erase(fullName.begin() + i);
            accountNumber.erase(accountNumber.begin() + i);
            streetAddress.erase(streetAddress.begin() + i);
            city.erase(city.begin() + i);
            state.erase(state.begin() + i);
            zipCode.erase(zipCode.begin() + i);
            phoneNumber.erase(phoneNumber.begin() + i);
        }
        else {
            ++i;
        }
    }
    writeToUpdateFile();

}
void customerData::writeToUpdateFile()
{

    ofstream outFile("CustomerDataOutPut.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < accountNumber.size(); ++i) {
        outFile << accountNumber[i] << endl;
        outFile << fullName[i] << endl;
        outFile << streetAddress[i] << endl;
        outFile << city[i] << endl;
        outFile << state[i] << endl;
        outFile << zipCode[i] << endl;
        outFile << phoneNumber[i] << endl << endl;
    }

    outFile.close();
}

void customerData::updateFile(int fieldChoice, int index, const string& userInput)
{


    if (index < 0 || index >= accountNumber.size()) {
        cerr << "Invalid index.\n";
        return;
    }
   
    string street, newCity, newState, zip, phone, name;
    switch (fieldChoice) {
    case 1: // Update Account Number
        accountNumber[index] = userInput;
        break;
    case 2: 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "what is the new full name: ";
        getline(cin, name);
        fullName[index] = name;
        break;
    case 3:
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new street address: ";
        getline(cin, street);
        cout << "Enter new city: ";
        getline(cin, newCity);
        cout << "Enter new state: ";
        getline(cin, newState);
        cout << "Enter new ZIP code: ";
        getline(cin, zip);

        streetAddress[index] = street;
        city[index] = newCity;
        state[index] = newState;
        zipCode[index] = zip;
        break;
    case 4:
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (true) {
            cout << "Enter new phone number: ";

            getline(cin,phone);
            //checkes to make sure the data is the length of 10 but also checks that from begging to end all the characters are digits
            if (phone.length() != 10 || !all_of(phone.begin(), phone.end(), ::isdigit)) {
                cout << "Invalid input. Phone number must be exactly 10 digits.\n";
                continue;
            }
            phoneNumber[index] = phone;
            break;

        }
        break;
      
    default:
        cout << "Invalid option" << endl;
  
    }

    writeToUpdateFile();  // Save changes back to file




}

//gets the data out at specfic parts
string customerData::get_accountNum(int index)
{

    if (index < 0 || index >= accountNumber.size()) return "";
    return accountNumber[index];
}

string customerData::get_name(int index)
{
    if (index < 0 || index >= fullName.size()) return "";
    return fullName[index];
}

string customerData::get_area(int index)
{
    if (index < 0 || index >= streetAddress.size()) return "";
    return streetAddress[index] + ", " + city[index] + ", " + state[index];
}

string customerData::get_codeANDnumber(int index)
{
    if (index < 0 || index >= zipCode.size()) return "";
    return "Zip Code: " + zipCode[index] + ", Phone: " + phoneNumber[index];
}


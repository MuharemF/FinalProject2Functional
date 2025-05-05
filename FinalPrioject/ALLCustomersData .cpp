#include "AllCustomersData .h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


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
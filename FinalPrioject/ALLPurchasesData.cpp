#include "ALLPurchasesData.h"
#include "ALLCustomersData .h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
void purchasesData::readInFile() {
    ifstream fin("PurchasesData.txt");
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string accountNum, item, date, line;
    double price;
    readInPurchase = 0;

    while (getline(fin, accountNum)) {
        if (accountNum.empty()) continue;

        //this loop is needed as there are customers who will have more then 1 item purchased 
        while (getline(fin, item)) {
            if (item.empty()) break;

            if (!getline(fin, date)) break;
            if (!(fin >> price)) break;
            fin.ignore(); // newline after number

            set_accountNumber(accountNum); // 
            set_item(item);
            set_date(date);
            set_priceItem(price);
            readInPurchase++;
        }
    }


    fin.close();
}

void purchasesData::thingsSold(int numOftimes) {
    ofstream purchasesOut("PurchasesDataOutPut.txt", ios::app);
    if (!purchasesOut.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    cout << "What would you like to purchase? " << endl;
    cout << "1. Square for $690.420 " << endl;
    cout << "2. circle for $360 " << endl;
    cout << "3. A right triangle for $90" << endl;
    cout << "4. A rectangle (3*4) for $12000" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      
        purchasesOut << "Square" << endl << "05/12/25" << endl << 690.420 << endl;
        
        break;
    case 2:
       
        
        purchasesOut << "Circle" << endl << "05/12/25" << endl << 360 << endl;
        
        break;
    case 3:
     
       
        purchasesOut << "Right triangle " << endl << "05/12/25 " << endl << 90 << endl;
        
        break;
    case 4:
        
       
        purchasesOut << "Rectangle (3*4)" << endl << "05/12/25" << endl << 12000 << endl;
        
        break;

    }
   
    if (numOftimes != 1) {
       
        thingsSold(numOftimes - 1);
         purchasesOut << endl;
    }
    readOutFile();

}
void purchasesData::thingsSoldForUpdate(int numOftimes, const string& accountNum) {
    ofstream purchasesOut("PurchasesDataOutPut.txt", ios::app);
    if (!purchasesOut.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int choice;
    for (int i = 0; i < numOftimes; ++i) {
        cout << "What would you like to purchase? " << endl;
        cout << "1. Square for $690.420 " << endl;
        cout << "2. Circle for $360 " << endl;
        cout << "3. A right triangle for $90" << endl;
        cout << "4. A rectangle (3*4) for $12000" << endl;
        cin >> choice;

        string item, date = "05/12/25";
        double price = 0;

        switch (choice) {
        case 1: item = "Square"; price = 690.420; break;
        case 2: item = "Circle"; price = 360; break;
        case 3: item = "Right triangle"; price = 90; break;
        case 4: item = "Rectangle (3*4)"; price = 12000; break;
        default: cout << "Invalid item choice.\n"; continue;
        }

        purchasesOut << accountNum << endl;
        purchasesOut << item << endl;
        purchasesOut << date << endl;
        purchasesOut << price << endl << endl;
    }

    purchasesOut.close();
    readOutFile(); // Reload into memory
}


void purchasesData::deletePurchasesByAccount(string accountNumToDelete) {
    for (size_t i = 0; i < accountNumber.size();) {
        if (accountNumber[i] == accountNumToDelete) {
            accountNumber.erase(accountNumber.begin() + i);
            item.erase(item.begin() + i);
            date.erase(date.begin() + i);
            priceOfItem.erase(priceOfItem.begin() + i);
        }
        else {
            ++i;
        }
    }
    writeAllToFile();
  
}


void purchasesData::writeAllToFile() {
    ofstream outFile("PurchasesData.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (size_t i = 0; i < accountNumber.size(); ++i) {
        outFile << accountNumber[i] << endl;
        outFile << item[i] << endl;
        outFile << date[i] << endl;
        outFile << priceOfItem[i] << endl << endl;
    }

    outFile.close();
}
void purchasesData::writeToUpdateFile() {
    ofstream outFile("PurchasesDataOutPut.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (size_t i = 0; i < accountNumber.size(); ++i) {
        outFile << accountNumber[i] << endl;
        outFile << item[i] << endl;
        outFile << date[i] << endl;
        outFile << priceOfItem[i] << endl << endl;
    }

    outFile.close();
}
void purchasesData::deletePurchasesByAccountOutFile(string accountNumToDelete) {
    for (size_t i = 0; i < accountNumber.size();) {
        if (accountNumber[i] == accountNumToDelete) {
            accountNumber.erase(accountNumber.begin() + i);
            item.erase(item.begin() + i);
            date.erase(date.begin() + i);
            priceOfItem.erase(priceOfItem.begin() + i);
        }
        else {
            ++i;
        }
    }
    writeToUpdateFile();

}
void purchasesData::updateFile(int fieldChoice, int index, const string& userInput) {
    if (index < 0 || index >= accountNumber.size()) {
        cerr << "Invalid index.\n";
        return;
    }
    string oldAcc = accountNumber[index];
    switch (fieldChoice) {
    case 1: { // Account Number change
       

        for (size_t i = 0; i < accountNumber.size(); ++i) {
            if (accountNumber[i] == oldAcc) {
                accountNumber[i] = userInput;
            }
        }
        break;
    }

   
    case 5: {
        int amountItmesBought;
        cout << "How many items did they buy: ";
        cin >> amountItmesBought;
        thingsSoldForUpdate(amountItmesBought, accountNumber[index]);
        break;
    }

    

    default:
        // Do nothing for fields 2, 3, or 4
        break;
    }

    writeToUpdateFile(); // Save all changes
}


void purchasesData::writUpdatedInfoFile(int amountItemsBought) {
    ofstream outFile("PurchasesDataOutPut.txt");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (size_t i = 0; i < accountNumber.size(); ++i) {
        outFile << accountNumber[i] << endl;
        outFile << item[i] << endl;
        outFile << date[i] << endl;
        outFile << priceOfItem[amountItemsBought] << endl << endl;
    }

    outFile.close();

}

void purchasesData::readOutFile() {
    ifstream fin("PurchasesDataOutPut.txt");
    if (!fin.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }


    fin.seekg(0, ios::end); // move to end
    if (fin.tellg() == 0) { // check if position is 0

        cout << "File is empty" << endl;
        return;
    }
    fin.seekg(0); // reset to beginning if needed

    string accountNum, item, date, line;
    double price;
    readInPurchase = 0;

    while (getline(fin, accountNum)) {
        if (accountNum.empty()) continue;

        //this loop is needed as there are customers who will have more then 1 item purchased 
        while (getline(fin, item)) {
            if (item.empty()) break;

            if (!getline(fin, date)) break;
            if (!(fin >> price)) break;
            fin.ignore(); // newline after number

            set_accountNumber(accountNum); // 
            set_item(item);
            set_date(date);
            set_priceItem(price);
            readInPurchase++;
        }
    }


    fin.close();
}
string purchasesData::get_accountNum(int index)
{
    if (index < 0 || index >= accountNumber.size()) return "";
    return accountNumber[index];
}

string purchasesData::get_item(int index)
{
    if (index < 0 || index >= item.size()) return "";
    return item[index];
}

string purchasesData::get_date(int index)
{
    if (index < 0 || index >= date.size()) return "";
    return date[index];
}



double purchasesData::get_itemPrice(int index)
{
    if (index < 0 || index >= priceOfItem.size()) return 0;
    return priceOfItem[index];
}









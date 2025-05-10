#include "ALLPurchasesData.h"
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

void purchasesData::readOutFile() {
    ifstream fin("PurchasesDataOutPut.txt");
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
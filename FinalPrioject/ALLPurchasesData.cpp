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
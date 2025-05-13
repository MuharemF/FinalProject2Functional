#ifndef PURCHASESDATA_H
#define PURCHASESDATA_H

#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
extern double readInPurchase;
class purchasesData { //Creates line 'objects'
private:
	vector<string> accountNumber;
	vector<string> item;
	vector<string> date;
	vector<double> priceOfItem;
	vector<double> totalCost;
	vector<string> holdData;
	vector<int> holdIntData;


public:
	//logic
	void readInFile();
	void readOutFile();
	void thingsSold(int numOftimes);
	void deletePurchasesByAccount(string accountNumToDelete);
	void writeAllToFile();
	void updateFile(int fieldChoice, int index, const string& userInput);
	void writeToUpdateFile();
	void deletePurchasesByAccountOutFile(string accountNumToDelete);
	void writUpdatedInfoFile(int amountItemsBought);
	void thingsSoldForUpdate(int numOftimes, const string& accountNum);
	//Getters
	string get_accountNum(int index);
	string get_item(int index);
	string get_date(int index);
	double get_itemPrice(int index);


	//setters
	void set_accountNumber(string accountNum) { accountNumber.push_back(accountNum); }
	void set_item(string thing) { item.push_back(thing); }
	void set_date(string timeOfYear) { date.push_back(timeOfYear); }
	void set_priceItem(double itemPrice) { priceOfItem.push_back(itemPrice); }
	
};




#endif
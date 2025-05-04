#ifndef PURCHASESDATA_H
#define PURCHASESDATA_H

#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class purchasesData { //Creates line 'objects'
private:
	vector<string> accountNumber;
	vector<string> item;
	vector<string> date;
	vector<int> amount;


public:
	void readInFile();
	//Getters
	string get_accountNum();
	string get_item();
	string get_data();
	int get_amount();


	//setters
	void set_item(string thing) { item.push_back(thing); }
	void set_date(string timeOfYear) { date.push_back(timeOfYear); }
	void set_amount(int total) { amount.push_back(total); }

};




#endif
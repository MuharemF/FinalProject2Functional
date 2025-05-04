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
	//Getters



	//setters
	void set_item(string thing) { item.push_back(thing); }
	void set_date(string timeOfYear) { date.push_back(timeOfYear); }
	void set_amount(int total) { amount.push_back(total); }

};




#endif


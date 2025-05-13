#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
extern int readIn;
class customerData {
private:
	vector<string> fullName;
	vector<string> accountNumber;
	vector <string> streetAddress;
	vector<string> city;
	vector<string> state;
	vector<string> zipCode;
	vector<string> phoneNumber;
	vector<string> customers;




public:
	//logic
	void read_all_data();
	void readCustomOutData();
	void deleteCustomerByAccount(string accountNumToDelete);
	void writeToInFile();
	void updateFile(int fieldChoice, int userIndex, const string& userInput);
	void writeToUpdateFile();
	void deleteCustomerByAccountOutFile(string accountNumToDelete);

	//Getters
	string get_name(int index);
	string get_area(int index);
	string get_codeANDnumber(int index);
	string get_accountNum(int index);
	


	//setters
	void set_name(string name) { fullName.push_back(name); }
	void set_area(string cty, string ste, string street) { streetAddress.push_back(street); city.push_back(cty);state.push_back(ste); }
	void set_codeANDnumber(string zip, string number) { zipCode.push_back(zip); phoneNumber.push_back(number); }
	void set_accountNumber(string num) { accountNumber.push_back(num); }




};




#endif


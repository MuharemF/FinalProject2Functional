#include <iostream>
#include "AllCustomersData .h"
#include "ALLPurchasesData.h"
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int readIn = 0;
customerData test;
purchasesData test2;
double readInPurchase = 0;
void printAll() {
	
	test.read_all_data();
	
	test2.readInFile();
	double totalCost = 0;


	//displays the amount of customers name account etc
	for (int i = 0; i < readIn; i++) {
		cout << "Customer " << i + 1 << ":\n";
		cout << "	Name: " << test.get_name(i) << endl;
		cout << "	Account: " << test.get_accountNum(i) << endl;
		cout << "	Area: " << test.get_area(i) << endl;
		cout << "	Contact: " << test.get_codeANDnumber(i) << endl;
		//This loop is just for reading in the data from the purchasesData.txt file and just add the data to the customer
		for (int j = 0; j < readInPurchase; j++) {
			//checking to see if account nums are the same for each other 
			if (test2.get_accountNum(j) == test.get_accountNum(i)) {
				cout << "	Item purchased: " << test2.get_item(j) << endl;
				cout << "	Date: " << test2.get_date(j) << endl;
				cout << "	Price of the item: " << test2.get_item(j) << " is: " << test2.get_itemPrice(j) << endl;
				totalCost += test2.get_itemPrice(j);
				

			}
			
		}
		cout << "	The toal cost for Customer " << i + 1 << " is: " << totalCost << endl;
		totalCost = 0;
		cout << "------------------------------------------------------" << endl;

	}
}
void printSpecficCustomer() {
	readInPurchase = 0;
	test.read_all_data();
	test2.readInFile();
	int choice;
	int purchaseCount = 0;
	double totalCost = 0;
	do {
		cout << "There are a total of " << readIn << " customers which one whould you like to see? (type -1 to exit) " << endl;
		for (int i = 0;i < readIn;i++) {
			cout << i + 1 << ". "  << test.get_name(i) << endl;
		}
		cin >> choice;
		cout << "----------------------------------------------------------" << endl;
		if (choice == -1) {
			break;
		}
		if (cin.fail()||choice>readIn||choice<=0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}
		for (int i = 0; i < readInPurchase; i++) {
			if (test2.get_accountNum(i) == test.get_accountNum(choice-1)) {
				purchaseCount++;
			}
		}
		cout << "Now viewing the data of Customer " << choice << endl << endl;
		cout << "	Name: " << test.get_name(choice-1) << endl << endl;
		cout << "	Account: " << test.get_accountNum(choice - 1) << endl << endl;
		cout << "	Area: " << test.get_area(choice - 1) << endl << endl;
		cout << "	Contact: " << test.get_codeANDnumber(choice - 1) << endl << endl;
		cout <<"	" << test.get_name(choice - 1) << " has a total of " << purchaseCount << " items purchased " << endl << endl;
		int itemNum = 1;
		for (int i = 0;i < readInPurchase;i++) {
			if (test2.get_accountNum(i) == test.get_accountNum(choice - 1)) {
				cout << "	Item " << itemNum << " that was purchased: " << test2.get_item(i) << endl << endl;
				cout << "	Date: " << test2.get_date(i) << endl << endl;
				cout << "	Price of the item: " << test2.get_item(i) << " is: " << test2.get_itemPrice(i) << endl << endl;
				totalCost += test2.get_itemPrice(i);
				itemNum++;
			}
			
		}
		
		cout << "	The total cost that " << test.get_name(choice - 1) << " spent is " << totalCost << endl;
		totalCost = 0;
		purchaseCount = 0;
		itemNum = 1;
		cout << "----------------------------------------------------------" << endl;

	} while (choice != -1);

	







}
void printOutData() {
	test2.readOutFile();
	test.readCustomOutData();
	double totalCost = 0;


	//displays the amount of customers name account etc
	for (int i = 0; i < readIn; i++) {
		cout << "Customer " << i + 1 << ":\n";
		cout << "	Name: " << test.get_name(i) << endl;
		cout << "	Account: " << test.get_accountNum(i) << endl;
		cout << "	Area: " << test.get_area(i) << endl;
		cout << "	Contact: " << test.get_codeANDnumber(i) << endl;
		//This loop is just for reading in the data from the purchasesData.txt file and just add the data to the customer
		for (int j = 0; j < readInPurchase; j++) {
			//checking to see if account nums are the same for each other 
			if (test2.get_accountNum(j) == test.get_accountNum(i)) {
				cout << "	Item purchased: " << test2.get_item(j) << endl;
				cout << "	Date: " << test2.get_date(j) << endl;
				cout << "	Price of the item: " << test2.get_item(j) << " is: " << test2.get_itemPrice(j) << endl;
				totalCost += test2.get_itemPrice(j);


			}

		}
		cout << "	The toal cost for Customer " << i + 1 << " is: " << totalCost << endl;
		totalCost = 0;
		cout << "------------------------------------------------------" << endl;

	}

}
void addNewCustomer(int choice) {
	purchasesData amountItemBought;
	ofstream purchasesOut("PurchasesDataOutPut.txt",ios::app);
	if (!purchasesOut.is_open()) {
		cerr << "Error: Unable to open file." << endl;
		return;
	}
	ofstream customerOut("CustomerDataOutPut.txt", ios::app);
	int numOfcustom, Idnum, zip, itemNum;
	string name, state, city, street, phoneNum;

	cout << "This is for customer " << choice;
	//Ask for IDNUM
	while (true) {
		cout << " Enter a 4 digit long Id number " << endl;
		cin >> Idnum;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.fail() || to_string(Idnum).length() < 4 || to_string(Idnum).length() > 4) {
			cin.clear(); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}
		else {
			break;
		}
	}
	
	purchasesOut << Idnum << endl;
	customerOut << Idnum << endl;
	cout << " what is name " << endl;

	getline(cin, name);

	cout << "what is state " << endl;
	getline(cin, state);
	
	cout << "what is city " << endl;
	getline(cin, city);
	
	cout << "What is street " << endl;
	getline(cin, street);
	while (true) {
		cout << "What is the zip code (5 digits)" << endl;
		cin >> zip;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.fail() || to_string(zip).length() < 5|| to_string(zip).length() >5) {
			cin.clear();
			
			cout << "Invalid input. \n";
			continue;
		}
		else {
			break;
		}
	}
	while (true) {
		cout << "What is phone number (10 digits): ";
		getline(cin, phoneNum);

		// Check if it's exactly 10 digits and all characters are digits
		if (phoneNum.length() != 10 || !all_of(phoneNum.begin(), phoneNum.end(), ::isdigit)) {
			cout << "Invalid input. Phone number must be exactly 10 digits.\n";
			continue;
		}


		break;
	}

	while (true) {
		cout << "How many items did " << name << " buy? ";
		cin >> itemNum;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.fail() || itemNum < 0) {
			cin.clear();
			
			cout << "Invalid input. \n";
			continue;
		}
		else {
			break;
		}
	}
	
	amountItemBought.thingsSold(itemNum);
	customerOut << name << endl << state << endl << city << endl << street << endl <<  zip <<endl << phoneNum << endl << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	if (choice != 1) {
		addNewCustomer(choice - 1);

	}
	else {
		printOutData();
	}
	

}



void mainMenu() {
	int choice, amountOfCustomers;
	cout << "Welcome to the spring 211 final project " << endl;
	cout << "Choose what you want to do " << endl;

	do {
	
		cout << "1. View all the customers we have " << endl;
		cout << "2. Sort and print Customer list in descending or ascending order " << endl;
		cout << "3. View specific customer's account information along with all purchases ";
		cout << "4. view all customer's purchases " << endl;
		cout << "5. Add a new customer " << endl;
		cout << "6. Update or delete a customers information" << endl;
		cout << "7. Add new customer purchases " << endl;
		cout << "8. Exit " << endl;
		cin >> choice;
		if (choice == 8) {
			cout << "Exiting program . . ." << endl;
			break;
		}
		if (cin.fail() || choice >= 8 || choice <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}
		
		switch (choice) {
		case 1:
			printAll();
			break;
		case 3:
			printSpecficCustomer();
			break;
		case 5:
		
			while(true) {
				cout << "How many customers are you adding: ";
				cin >> amountOfCustomers;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (cin.fail() || amountOfCustomers <= 0) {
					cin.clear();
					cout << "Invalid input. \n";
					continue;
				}
				else { break; }
			}
			
			addNewCustomer(amountOfCustomers);
			


		}


	} while (choice != 8);
}



int main() {
	mainMenu();
	
	

	return 0;

}
#include <iostream>
#include "AllCustomersData .h"
#include "ALLPurchasesData.h"
#include <string>
#include <fstream>
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
	test.read_all_data();
	test2.readInFile();
	int choice;
	do {
		cout << "There are a total of " << readIn << " customers which one whould you like to see? (type -1 to exit) ";
		cin >> choice;
		cout << "----------------------------------------------------------" << endl;
		if (choice == -1) {
			break;
		}
		if (cin.fail()||choice>=readIn||choice<=0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}

		cout << "Now viewing the data of Customer " << choice << endl;
		cout << "	Name: " << test.get_name(choice-1) << endl;
		cout << "	Account: " << test.get_accountNum(choice - 1) << endl;
		cout << "	Area: " << test.get_area(choice - 1) << endl;
		cout << "	Contact: " << test.get_codeANDnumber(choice - 1) << endl;
		for (int i = 0;i < readInPurchase;i++) {
			if (test2.get_accountNum(i) == test.get_accountNum(choice - 1)) {
				cout << "	Item purchased: " << test2.get_item(i) << endl;
				cout << "	Date: " << test2.get_date(i) << endl;
				cout << "	Price of the item: " << test2.get_item(i) << " is: " << test2.get_itemPrice(i) << endl;
			}
			
		}
		cout << "----------------------------------------------------------" << endl;

	} while (choice != -1);

	







}


void mainMenu() {
	int choice;
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


		}


	} while (choice != 8);
}



int main() {
	mainMenu();
	/*printSpecficCustomer();*/


	return 0;

}
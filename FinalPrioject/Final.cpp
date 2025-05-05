#include <iostream>
#include "AllCustomersData .h"
#include "ALLPurchasesData.h"
#include <string>
#include <fstream>
using namespace std;
int readIn = 0;
double readInPurchase = 0;
void printAll() {
	customerData test;
	test.read_all_data();
	purchasesData test2;
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
		switch (choice) {
		case 1:
			printAll();
			break;


		}


	} while (choice != 8);
}



int main() {
	mainMenu();



	return 0;

}
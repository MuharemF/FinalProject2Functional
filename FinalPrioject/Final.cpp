#include <iostream>
#include "AllCustomersData .h"
#include "ALLPurchasesData.h"
#include <string>
#include <fstream>
using namespace std;
int readIn = 0;

void printAll() {
	customerData test;
	test.read_all_data();



	//to increase this we have to make another loop that soly reads the file and counts the amount of items read
	for (int i = 0; i < readIn; ++i) {
		cout << "Customer " << i + 1 << ":\n";
		cout << "  Name: " << test.get_name(i) << endl;
		cout << "  Account: " << test.get_accountNum(i) << endl;
		cout << "  Area: " << test.get_area(i) << endl;
		cout << "  Contact: " << test.get_codeANDnumber(i) << endl << endl;

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
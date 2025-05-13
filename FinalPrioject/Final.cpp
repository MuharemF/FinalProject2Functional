#include <iostream>
#include "AllCustomersData .h"
#include "ALLPurchasesData.h"
#include <string>
#include <fstream>
#include <algorithm>//used for sort function
using namespace std;
int readIn = 0;
double readInPurchase = 0;
void printAll() {
	customerData test;
	purchasesData test2;
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
void printSpecInFile() {
	customerData test;
	purchasesData test2;
	readInPurchase = 0;
	test.read_all_data();
	test2.readInFile();
	int choice;
	int purchaseCount = 0;
	double totalCost = 0;

	do {
		cout << "There are a total of " << readIn << " customers which one whould you like to see?" << endl;
		for (int i = 0;i < readIn;i++) {
			cout << i + 1 << ". " << test.get_name(i) << endl;
		}
		cout << readIn + 1 << ". Exit ";
		cin >> choice;
		if (choice == readIn + 1) {
			cout << "Exiting from viewing specfic customers " << endl;
			break;
		}
		cout << "----------------------------------------------------------" << endl;

		if (cin.fail() || choice > readIn || choice <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}
		//to get a total number the persion chosen
		for (int i = 0; i < readInPurchase; i++) {
			if (test2.get_accountNum(i) == test.get_accountNum(choice - 1)) {
				purchaseCount++;
			}
		}
		//taken from the print all function this makes it so we can see the user printed
		cout << "Now viewing the data of Customer " << choice << endl << endl;
		cout << "	Name: " << test.get_name(choice - 1) << endl << endl;
		cout << "	Account: " << test.get_accountNum(choice - 1) << endl << endl;
		cout << "	Area: " << test.get_area(choice - 1) << endl << endl;
		cout << "	Contact: " << test.get_codeANDnumber(choice - 1) << endl << endl;
		cout << "	" << test.get_name(choice - 1) << " has a total of " << purchaseCount << " items purchased " << endl << endl;
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
void printSpecOutCustomer() {

	customerData test;
	purchasesData test2;
	readInPurchase = 0;
	test.readCustomOutData();
	test2.readOutFile();
	int choice;
	int purchaseCount = 0;
	double totalCost = 0;

	do {
		cout << "There are a total of " << readIn << " customers which one whould you like to see? " << endl;
		for (int i = 0;i < readIn;i++) {
			cout << i + 1 << ". " << test.get_name(i) << endl;
		}
		cout << readIn + 1 << ". Exit ";
		cin >> choice;
		if (choice == readIn + 1) {
			cout << "Exiting from viewing specfic customers " << endl;
			break;
		}
		cout << "----------------------------------------------------------" << endl;

		if (cin.fail() || choice > readIn || choice <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}
		//to get a total number the persion chosen
		for (int i = 0; i < readInPurchase; i++) {
			if (test2.get_accountNum(i) == test.get_accountNum(choice - 1)) {
				purchaseCount++;
			}
		}
		//taken from the print all function this makes it so we can see the user printed
		cout << "Now viewing the data of Customer " << choice << endl << endl;
		cout << "	Name: " << test.get_name(choice - 1) << endl << endl;
		cout << "	Account: " << test.get_accountNum(choice - 1) << endl << endl;
		cout << "	Area: " << test.get_area(choice - 1) << endl << endl;
		cout << "	Contact: " << test.get_codeANDnumber(choice - 1) << endl << endl;
		cout << "	" << test.get_name(choice - 1) << " has a total of " << purchaseCount << " items purchased " << endl << endl;
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
void printSpecficCustomer() {


	int choice;
	while (true) {
		cout << "From which file do you want to specfically print out from? " << endl;
		cout << "1. From the orginal " << endl;
		cout << "2. From the Output file" << endl;
		cout << "3. Exit" << endl;
		//for view specfic data in output file
	
		cin >> choice;
		if (choice == 3) {
			cout << "Exiting back to main menu " << endl;
			cout << "------------------------------------------------------" << endl;
			break;
		}
		
		if (cin.fail() || choice <= 0|| choice > 3) {
			cin.clear(); // Clear input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. \n";
			continue;
		}
		switch (choice) {
		case 1:
			printSpecInFile();
			break;
		case 2:
			printSpecOutCustomer();
			break;
		}



	}

	


}
//This is for printing out the Data in the output files
void printOutData() {


	customerData test;
	purchasesData test2;
	test2.readOutFile();
	test.readCustomOutData();
	double totalCost = 0;


	//displays the amount of customers name account etc
	cout<<"------------------------------------------------------"<<endl;
	for (int i = 0; i < readIn; i++) {
		cout << "Customer " << i + 1 << ":\n";
		cout << "	Name: " << test.get_name(i) << endl;
		cout << "	Account: " << test.get_accountNum(i) << endl;
		cout << "	Area: " << test.get_area(i) << endl;
		cout << "	Contact: " << test.get_codeANDnumber(i) << endl;
		//This loop is just for reading in the data from the purchasesData.txt file and just add the data to the customer
		for (int j = 0; j < readInPurchase; j++) {
			//checking to see if account nums are the same for each other 
			if (test2.get_accountNum(j) != test.get_accountNum(i)) {
				test.get_accountNum(i) = test2.get_accountNum(j);
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
		//checking to make sure the ID num is right length
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
	cout << " What is the name name of this person: " << endl;
	getline(cin, name);
	cout << "What is the state they live in: " << endl;
	getline(cin, state);	
	cout << "What is the city they live in: " << endl;
	getline(cin, city);	
	cout << "What is the street they live on: " << endl;
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
	cout << "------------------------------------------------------" << endl;
	//this is just to see if the user is adding more then 1 customer if they are run through the whole function again (god bless)
	if (choice != 1) {
		addNewCustomer(choice - 1);

	}
	else {
		printOutData();
	}
	

}
//this is used to make the selection in the update function cleaner 
int selectCustomer() {
	customerData test;
	purchasesData test2;
	test.read_all_data();
	test2.readInFile();

	int choice;


	while (true) {
		cout << "There are a total of " << readIn << " customers. Which one would you like to select?\n";
		for (int i = 0; i < readIn; i++) {
			cout << i + 1 << ". " << test.get_name(i) << endl;
		}
		cout << readIn + 1 << ". Exit" << endl;
		cin >> choice;
		if (choice == readIn + 1) {
			cout << "Returning to main menu . . . " << endl;
			cout << "------------------------------------------------------" << endl;
			return choice;
		}
		
		if (cin.fail() || choice <= 0 || choice > readIn+1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}
		break;

	}
	

	return choice - 1;
}

void update() {
	customerData test;
	purchasesData test2;
	test.read_all_data();
	test2.readInFile();
	int customerIndex = selectCustomer();
	if (customerIndex == readIn + 1) {
		return;
	}
	//currentAccount is used for when the user is not chaning the the ID number
	string currentAccount = test.get_accountNum(customerIndex-1);

	int choice;

	while (true) {
		cout << "\nWhat would you like to update for this customer?\n";
		cout << "1. Account Number\n";
		cout << "2. Name\n";
		cout << "3. Address (street, city, state, ZIP)\n";
		cout << "4. Phone Number\n";
		cout << "5. Purchased Items\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail() || choice <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}
		break;
	}
	

	switch (choice) {
	case 1: {
		int newAccountNum;
		while (true) {
			cout << "Enter the new 4-digit account number: ";
			cin >> newAccountNum;
			
			if (cin.fail() || to_string(newAccountNum).length() != 4) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Must be 4 digits.\n";
				continue;
			}
			break;
		}
		test.updateFile(choice, customerIndex, to_string(newAccountNum));
		test2.updateFile(choice, customerIndex, to_string(newAccountNum));
		break;
	}
	case 2:
	case 3:
	case 4:

		test.updateFile(choice, customerIndex, currentAccount);
		test2.updateFile(choice, customerIndex, currentAccount);
		break;
	case 5:
		test.updateFile(choice, customerIndex, currentAccount);
		test2.updateFile(choice, customerIndex, currentAccount);
		break;
	default:
		cout << "Invalid choice.\n";
	}
	
	test.readCustomOutData();
	test2.readOutFile();
	system("Pause");
	int purchaseCount = 0;
	double totalCost = 0;
	for (int i = 0; i < readInPurchase; i++) {
		if (test2.get_accountNum(i) == test.get_accountNum(choice - 1)) {
			purchaseCount++;
		}
	}
	cout << "The customer has been updated " << endl;
	cout << "---------------------------------------------------------" << endl;



}
void deleteOgFile() {
	customerData test;
	purchasesData test2;
	readInPurchase = 0;
	test.read_all_data();     // Load customer data
	test2.readInFile();       // Load purchases data

	int choice;
	do {
		cout << "There are a total of " << readIn << " customers. Which one would you like to delete? (Note once deleted you can not get them back) " << endl;
		for (int i = 0; i < readIn; i++) {
			cout << i + 1 << ". " << test.get_name(i) << " (" << test.get_accountNum(i) << ")" << endl;
		}
		cout << readIn + 1 << ". Exit" << endl;
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == readIn + 1) {
			cout << "Exiting returning back to main menu . . ." << endl;
			cout << "------------------------------------------------------" << endl;
			break;
		}

		if (cin.fail() || choice <= 0 || choice > readIn + 1) {
			cin.clear();
			cout << "Invalid input.\n";
			continue;
		}

		string accountToDelete = test.get_accountNum(choice - 1);

		// Delete from both classes
		test.deleteCustomerByAccount(accountToDelete);
		test2.deletePurchasesByAccount(accountToDelete);


		cout << "Customer and their purchases successfully deleted.\n";

	} while (true);


}
void deleteOutfile() {
	customerData test;
	purchasesData test2;
	readInPurchase = 0;
	test.readCustomOutData();     // Load customer data
	test2.readOutFile();       // Load purchases data

	int choice;
	do {
		if (readIn == 0) {
			cout << "There is no data in the file " << endl;
			cout << "------------------------------------------------------" << endl;
			return;
		}
		cout << "There are a total of " << readIn << " customers. Which one would you like to delete? (Note once you deleted them you can not get them back) " << endl;
		for (int i = 0; i < readIn; i++) {
			cout << i + 1 << ". " << test.get_name(i) << " (" << test.get_accountNum(i) << ")" << endl;
		}
		cout << readIn + 1 << ". Exit" << endl;
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == readIn + 1) {
			cout << "Exiting returning back to main menu . . ." << endl;
			cout << "------------------------------------------------------" << endl;
			break;
		}

		if (cin.fail() || choice <= 0 || choice > readIn + 1) {
			cin.clear();
			cout << "Invalid input.\n";
			continue;
		}

		string accountToDelete = test.get_accountNum(choice - 1);

		// Delete from both classes
		test.deleteCustomerByAccountOutFile(accountToDelete);
		test2.deletePurchasesByAccountOutFile(accountToDelete);


		cout << "Customer and their purchases successfully deleted.\n";

	} while (true);


}
void deleteFunction() {
	int choice;
	while (true) {
		cout << "From which file do you want to delete from? " << endl;
		cout << "1. Orginal" << endl;
		cout << "2. Output" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		if (choice == 3) {
			cout << "Returning to main menu . . ." << endl;
			cout << "------------------------------------------------------" << endl;
			return;
		}
		if (cin.fail() || choice <= 0 || choice > 3) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}

		switch (choice) {
		case 1:
			cout << "------------------------------------------------------" << endl;
			deleteOgFile();
			break;
		case 2:
			cout << "------------------------------------------------------" << endl;
			deleteOutfile();
			break;
		
		}


	}

}


void sortCustomerASC() {
	purchasesData data;
	data.readInFile();
	customerData test;
	test.read_all_data();
	vector<int> zeroOnward(readIn);
	for (int i = 0; i < zeroOnward.size(); i++) {
		zeroOnward[i] = i;
	}
		vector<int> indices(readInPurchase);
	for (int j = 0; j < indices.size(); ++j) {
		indices[j] = j;
	}

	// Step 2: Sort indices based on account number
	sort(indices.begin(), indices.end(), [&data](int a, int b) {
		return data.get_accountNum(a) > data.get_accountNum(b);
		});
	// Step 2: Sort indices based on account number
	sort(zeroOnward.begin(), zeroOnward.end(), [&test](int a, int b) {
		return test.get_accountNum(a) > test.get_accountNum(b);
		});

	// Step 3: output
	cout << "------------------------------------------------------" << endl;
	for (int i : zeroOnward) {
		cout << test.get_name(i) << endl;
		cout << test.get_accountNum(i) << endl;
		cout << test.get_area(i) << endl;
		cout << test.get_codeANDnumber(i) << endl;
		for (int j : indices) {
			if(test.get_accountNum(i)==data.get_accountNum(j)){
				cout << data.get_item(j) << endl;
				cout << data.get_date(j) << endl;
				cout << data.get_itemPrice(j) << endl;
			}
			
		}
		cout << "------------------------------------------------------" << endl;
	}
	
}

void sortCustomerDSC() {
	customerData test;
	test.read_all_data();

	purchasesData data;
	data.readInFile();

	// Step 1: Build indices
	vector<int> indices(readInPurchase);
	for (int j = 0; j < indices.size(); ++j) {
		indices[j] = j;
	}

	// Step 2: Sort indices based on account number
	sort(indices.begin(), indices.end(), [&data](int a, int b) {
		return data.get_accountNum(a) < data.get_accountNum(b);
		});

	vector<int> zeroOnward(readIn);
	for (int i = 0; i < zeroOnward.size(); i++) {
		zeroOnward[i] = i;
	}

	// Step 2: Sort indices based on account number
	sort(zeroOnward.begin(), zeroOnward.end(), [&test](int a, int b) {
		return test.get_accountNum(a) < test.get_accountNum(b);
		});
	cout << "------------------------------------------------------" << endl;
	// Step 3: Build customer strings in sorted order
	for (int i : zeroOnward) {	
		cout << test.get_name(i) << endl;
		cout << test.get_accountNum(i) << endl;
		cout << test.get_area(i) << endl;
		cout << test.get_codeANDnumber(i) << endl;
		for (int j : indices) {
			if (test.get_accountNum(i) == data.get_accountNum(j)) {
				cout << data.get_accountNum(i) << endl;
				cout << data.get_item(i) << endl;
				cout << data.get_date(i) << endl;
				cout << data.get_itemPrice(i) << endl;
			}
			
		}
		cout << "------------------------------------------------------" << endl;
	}

}

void sortOgFile() {
	int choice;
	do {

		while (true) {
			cout << "Choose how you want to sort these: " << endl;
			cout << "1. Ascending order (Those who have a higher numberd ID number) " << endl;
			cout << "2. Descending order (Those who have a lower numberd ID number)" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;
			if (choice == 3) {
				cout << "Exiting out of sorting returning the first option . . ." << endl;
				break;
			}
			if (cin.fail() || choice <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
				cout << "Invalid input. \n";
				continue;
			}
			break;
		}

		switch (choice)
		{
		case 1:
			sortCustomerASC();
			break;
		case 2:
			sortCustomerDSC();
			break;
		default:
			break;
		}



	} while (choice != 3);
	cout << "------------------------------------------------------" << endl;
}
void sortCustomerOutASC() {
	purchasesData data;
	data.readOutFile();
	customerData test;
	test.readCustomOutData();
	vector<int> zeroOnward(readIn);
	for (int i = 0; i < zeroOnward.size(); i++) {
		zeroOnward[i] = i;
	}
	vector<int> indices(readInPurchase);
	for (int j = 0; j < indices.size(); ++j) {
		indices[j] = j;
	}

	// Step 2: Sort indices based on account number
	sort(indices.begin(), indices.end(), [&data](int a, int b) {
		return data.get_accountNum(a) > data.get_accountNum(b);
		});
	// Step 2: Sort indices based on account number
	sort(zeroOnward.begin(), zeroOnward.end(), [&test](int a, int b) {
		return test.get_accountNum(a) > test.get_accountNum(b);
		});

	// Step 3: output
	cout << "------------------------------------------------------" << endl;
	for (int i : zeroOnward) {
		cout << test.get_name(i) << endl;
		cout << test.get_accountNum(i) << endl;
		cout << test.get_area(i) << endl;
		cout << test.get_codeANDnumber(i) << endl;
		for (int j : indices) {
			if (test.get_accountNum(i) == data.get_accountNum(j)) {
				cout << data.get_item(j) << endl;
				cout << data.get_date(j) << endl;
				cout << data.get_itemPrice(j) << endl;
			}

		}
		cout << "------------------------------------------------------" << endl;
	}

}

void sortCustomerOutDSC() {
	customerData test;
	test.readCustomOutData();

	purchasesData data;
	data.readInFile();

	// Step 1: Build indices
	vector<int> indices(readInPurchase);
	for (int j = 0; j < indices.size(); ++j) {
		indices[j] = j;
	}

	// Step 2: Sort indices based on account number
	sort(indices.begin(), indices.end(), [&data](int a, int b) {
		return data.get_accountNum(a) < data.get_accountNum(b);
		});

	vector<int> zeroOnward(readIn);
	for (int i = 0; i < zeroOnward.size(); i++) {
		zeroOnward[i] = i;
	}

	// Step 2: Sort indices based on account number
	sort(zeroOnward.begin(), zeroOnward.end(), [&test](int a, int b) {
		return test.get_accountNum(a) < test.get_accountNum(b);
		});
	cout << "------------------------------------------------------" << endl;
	// Step 3: Build customer strings in sorted order
	for (int i : zeroOnward) {
		cout << test.get_name(i) << endl;
		cout << test.get_accountNum(i) << endl;
		cout << test.get_area(i) << endl;
		cout << test.get_codeANDnumber(i) << endl;
		for (int j : indices) {
			if (test.get_accountNum(i) == data.get_accountNum(j)) {
				cout << data.get_accountNum(i) << endl;
				cout << data.get_item(i) << endl;
				cout << data.get_date(i) << endl;
				cout << data.get_itemPrice(i) << endl;
			}

		}
		cout << "------------------------------------------------------" << endl;
	}

}
void sortOutFile() {
	int choice;
	do {

		while (true) {
			cout << "------------------------------------------------------" << endl;
			cout << "Choose how you want to sort these: " << endl;
			cout << "1. Ascending order (Those who have a higher numberd ID number) " << endl;
			cout << "2. Descending order (Those who have a lower numberd ID number)" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;
			if (choice == 3) {
				cout << "Exiting returning to the first option . . ." << endl;
				cout << "------------------------------------------------------" << endl;
				break;
			}
			if (cin.fail() || choice <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
				cout << "Invalid input. \n";
				continue;
			}
			break;
		}

		switch (choice)
		{
		case 1:
			sortCustomerOutASC();
			break;
		case 2:
			sortCustomerOutDSC();
			break;
		default:
			break;
		}



	} while (choice != 3);
	
}



void sortFunction() {
	int choice;
	while (true) {
		cout << "What file do you want to sort?" << endl;
		cout << "1. Orginal File" << endl;
		cout << "2. Output file" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		if (choice == 3) {
			cout << "Exiting returning back to menu . . . " << endl;
			cout << "------------------------------------------------------" << endl;
			break;
		}
		if (cin.fail() || choice > 3 || choice <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer
			cout << "Invalid input. \n";
			continue;
		}

		switch (choice) {
		case 1:
			sortOgFile();
			break;
		case 2:
			sortOutFile();
			break;
		}

	}



}









void mainMenu() {
	int choice, amountOfCustomers;
	cout << "Welcome to the spring 211 final project " << endl;
	cout << "Choose what you want to do " << endl;

	do {
	
		cout << "1. View all the customers we have " << endl;
		cout << "2. Sort and print Customer list in descending or ascending order " << endl;
		cout << "3. View specific customer's account information along with all purchases " << endl;;
		cout << "4. Add a new customer " << endl;
		cout << "5. Update a customers information" << endl;
		cout << "6. Delete customers information " << endl;
		cout << "7. Exit " << endl;
		cin >> choice;
		if (choice == 7) {
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
			cout << "------------------------------------------------------" << endl;
			while (true) {
				cout << "Do you want to print the data in the orginal files or the output files " << endl;
				cout << "1. Orginal files " << endl;
				cout << "2. Output Files" << endl;
				cout << "3. Exit" << endl;

				cin >> choice;
				if (choice == 3) {
					cout << "Going back to main menu " << endl;
					cout << "------------------------------------------------------" << endl;
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
				case 2: 
					printOutData();
					break;
				default:
					cout << "invalid option" << endl;
				}

			}
			
			break;
		case 2: 
			cout << "------------------------------------------------------" << endl;
			sortFunction();
			break;
		case 3:
			cout << "------------------------------------------------------" << endl;
			printSpecficCustomer();
			break;
		case 4:
			cout << "------------------------------------------------------" << endl;
			while(true) {
				cout << "How many customers are you adding: ";
				cin >> amountOfCustomers;				
				if (cin.fail() || amountOfCustomers <= 0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. \n";
					continue;
				}
				else { break; }
			}		
			addNewCustomer(amountOfCustomers);
			break;
		case 5:
			cout << "------------------------------------------------------" << endl;
			update();
			break;
		case 6:
			cout << "------------------------------------------------------" << endl;
			deleteFunction();
			break;
			
		default:
			cout << "Invalid option" << endl;

		}


	} while (choice != 8);
}




int main() {
	cout << "Welcome to the 211 spring 2025 final project " << endl;
	cout << "note in the project when you see a long set of line like below that means that you are entering a new section of the program. " << endl;
	cout << "------------------------------------------------------" << endl;
	mainMenu();
	


	return 0;

}
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include"account.h"
#include"saving.h"
#include"trust.h"
#include"util.h"
#include"user.h"

using namespace std;



void menu() {

	cout << "\n1. Create an account" << endl;
	cout << "2. Withdraw from a single account" << endl;
	cout << "3. Deposit to a single account" << endl;
	cout << "4. Exit" << endl;
	cout << "5. Display a single account information" << endl;
	cout << "6. Display all account information" << endl;
	cout << "\nMeanu selection:";

}

double checking(double a) {

	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Wrong input";
		cin >> a;
		
	}

	return a;
}

int main() {
	int choice{ 0 };
	
	vector<user>accounts;


	cout << "Welcome to Crow's bank! " << endl;
	
	do {
		menu();
		cin >> choice;
		if (choice == 1) {
				double bal{ 0 };
				string name{ "" };
				bool check = true;
				cout << "\nInitial balance: ";
				cin >> bal;
				
				bal = checking(bal);
				
				cout << "\nName of the account: ";
				cin >> name;
				for (auto a : accounts) {
					if (a.name == name) {
						cin.ignore();
						cin.clear();
						cout << "Name is already being used" << endl;

						check = false;
					}
				}
				if (check == true) {
					accounts.push_back(user(name, bal));
					cout << "Account has been created" << endl;
				}
		}
		
		else if (choice == 2) {
			double withdraw{0};
			string name{ "" };
			bool check = false;
			cout << "\nWithdrawing " << endl;
			cout << "Printing account names" << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "Enter amount" << endl;
			cin >> withdraw;
			while (cin.fail()) {
				cout << "Wrong input" << endl;
				cout << "Enter again: ";
				cin.clear();
				cin.ignore();

				cin >> withdraw;
			}
			cout << "Enter name of account" << endl;
			cin >> name;
			for (int i{ 0 }; i < accounts.size(); i++) {
				if (accounts[i].name == name) {
					accounts[i].withdraw(withdraw);
					check = true;
				}
			}
			if (check == false) {
				cout << "There is no match account" << endl;
			}

		}
		else if (choice == 3) {
			double deposit{ 0 };
			string name{ "" };
			bool check = false;
			cout << "\nDepositing " << endl;
			cout << "Printing account names " << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "Enter amount " << endl;
			cin >> deposit;
			while (cin.fail()) {
				cout << "Wrong input" << endl;
				cout << "Enter again: ";
				cin.clear();
				cin.ignore();

				cin >> deposit;
			}
			cout << "Enter name " << endl;
			cin >> name;
			for (int i{ 0 }; i < accounts.size(); i++) {
				if (accounts[i].name == name) {
					accounts[i].deposit(deposit);
					check = true;
				}
			}
			if (check == false) {
				cout << "There is no match account" << endl;
			}


		}
		else if (choice == 4) {
			cout << "\nBye !" << endl;
			return 0;
		}


		else if (choice == 5) {
			string name{ "" };
			bool check = false;
			cout << "Printing account names " << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "Enter name " << endl;
			cin>>name;
			for (auto a : accounts) {
				if (a.name == name) {
					cout << a;
					check = true;
				}
				
			}
			if (check == false) {
				cout << "There is no matching account " << endl;
			}
			
		}

		else if (choice == 6) {
			display(accounts);
		}

		else {
			cin.clear();
			cin.ignore();
			cout << "Wrong input " << endl;
			cin >> choice;
		}

		
	} while (choice != 4);

	
	return 0;
	
}

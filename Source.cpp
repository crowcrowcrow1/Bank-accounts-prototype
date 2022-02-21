#include<iostream>
#include<vector>
#include<string>
#include"account.h"
#include"saving.h"
#include"trust.h"
#include"util.h"
#include"user.h"

using namespace std;



void menu() {

	cout << "\n1. create an account" << endl;
	cout << "2. withdraw from a single account" << endl;
	cout << "3. deposite to a single account" << endl;
	cout << "4. Exit" << endl;
	cout << "5. display a single account information" << endl;
	cout << "6. Display all account information" << endl;
	cout << "\nMeanu selection:";

}

int main() {
	int choice{ 0 };
	string name{ "" };
	double balance{ 0 };
	vector<user>accounts;


	cout << "Welcome to the bank" << endl;
	
	do {
		menu();
		cin >> choice;
		if (choice == 1) {
			cout << "\nwhat is name going to be? ";
			cin >> name;
			cout << "\nwhat is inital balance? (genral account) ";
			cin >> balance;
			accounts.push_back(user(name, balance));
		}
		
		else if (choice == 2) {
			int withdraw{0};
			string name{ "" };
			cout << "\nWhat would be the amount and from which account?" << endl;
			cout << "printing account names" << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "enter amount" << endl;
			cin >> withdraw;
			cout << "enter name" << endl;
			cin >> name;
			for (auto a : accounts) {
				if (a.name == name) {
					a.withdraw(withdraw);
				}
			}


		}
		else if (choice == 3) {
			int deposite{ 0 };
			string name{ "" };
			cout << "\nWhat would be the amount and to which account? " << endl;
			cout << "printing account names " << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "enter amount " << endl;
			cin >> deposite;
			cout << "enter name " << endl;
			cin >> name;
			for (auto a : accounts) {
				if (a.name == name) {
					a.deposite(deposite);
				}
			}



		}
		else if (choice == 4) {
			cout << "\nBye !" << endl;
			return 0;
		}


		else if (choice == 5) {
			string name{ "" };
			
			cout << "printing account names " << endl;
			for (auto a : accounts) {
				cout << a.name << endl;
			}
			cout << "which account do you want to see? enter name: " << endl;
			cin>>name;
			for (auto a : accounts) {
				if (a.name == name) {
					cout << a;
				}
			}
			cout << "There is no matching account " << endl;
			
		}

		else if (choice == 6) {
			display(accounts);
		}

		else {
			cin.ignore();
			cin.clear();
			cout << "Wrong " << endl;
			cin >> choice;
		}

		
	} while (choice != 4);

	
	return 0;
	
}

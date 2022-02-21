#include"user.h"
#include<string>
#include<iostream>
#include"checking.h"
#include"trust.h"



user::user(std::string n, double balance )
:name{n},balance{balance}
{
	
};
bool user::withdraw(double amount) {
	if (amount <= account::balance) {
		int choice;
		cout << "\nFrom which type account?" << endl;
		cout << "Saving is 1" << endl;
		cout << "Trust is 2" << endl;
		cout << "General account is 3\n" << endl;
		cin >> choice;
		do {
			if (choice == 1) {
				return saving::withdraw(amount);
			}

			if (choice == 2) {
				return trust::withdraw(amount);
			}
			if (choice == 3) {
				return account::withdraw(amount);
			}
			if (choice == 4) {
				return false;
			}
		} while (choice != 4);
		
	}
		
		cout << "nope you got no money" << endl;
		return false;
	

};
bool user:: deposite(double amount) {
	int choice;
	cout << "\nTo which type account?" << endl;
	cout << "Saving is 1" << endl;
	cout << "Trust is 2" << endl;
	cout << "General account is 3" << endl;
	cout << "4. Cancel\n" << endl;
	cin >> choice;
	do {
		if (choice == 1) {
			cout << "Depositing " << amount << "to saving account" << endl;
			return saving::deposite(amount);
		}

		if (choice == 2) {
			cout << "Depositing " << amount << "to trust account" << endl;
			return trust::deposite(amount);
		}
		if (choice == 3) {
			cout << "Depositing " << amount << "to account" << endl;
			return account::deposite(amount);
		}
		if (choice == 4) {
			return false;
		}
	} while (choice != 4);
	return false;
}


void user::print(ostream& os) {

	cout << "\nName of this account is: "<<name << endl;
	cout << "Total balance of accounts is: " << account::balance << endl;
	cout << "Balance of trust account is: " << trust::balance << endl;
	cout << "Balance of saving account is: " << saving::balance << endl;
	cout << "Thank you for using our bank\n" << endl;

};
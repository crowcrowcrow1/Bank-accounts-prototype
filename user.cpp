#include"user.h"
#include<string>
#include<iostream>
#include"checking.h"
#include"trust.h"


 
user::user(std::string n, double balance )
	:nameofuser{ n }
{
	
	account::balance = balance;
};
bool user::withdraw(double amount) {
	
		int choice;
		cout << "\nChoose account type" << endl;
		cout << "1. Saving" << endl;
		cout << "2. Trust" << endl;
		cout << "3. account\n" << endl;
		cout << "4. Exist" << endl;
		cin >> choice;
		do {
			if (choice == 1) {
				cout << "Withdrawing" << endl;
				return saving::withdraw(amount);
			}

			else if (choice == 2) {
				cout << "Withdrawing" << endl;
				return trust::withdraw(amount);
			}
			else if (choice == 3) {
				cout << "Withdrawing" << endl;
				return account::withdraw(amount);
			}
			else if (choice == 4) {
				return false;
			}
			else {
				cin.clear();
				cin.ignore();
				cout << "Wrong input" << endl;
				cin >> choice;
			}
		} while (choice != 4);
		return true;
	}
		
	
	


bool user:: deposit(double amount) {
	int choice;
	cout << "\nChoose account type" << endl;
	cout << "1. Saving" << endl;
	cout << "2. Trust" << endl;
	cout << "3. account" << endl;
	cout << "4. Cancel\n" << endl;
	cin >> choice;
	do {
		if (choice == 1) {
			cout << "Depositing $ " << amount << " to your saving account" << endl;
			return saving::deposit(amount);
		}

		else if (choice == 2) {
			cout << "Depositing $ " << amount << " to your trust account" << endl;
			return trust::deposit(amount);
		}
		else if (choice == 3) {
			cout << "Depositing $ " << amount << " to your account" << endl;
			return account::deposit(amount);
		}
		else if (choice == 4) {
			return false;
		}
		else {
			cin.clear();
			cin.ignore();
			cout << "Wrong input" << endl;
			cin >> choice;
		}
	} while (choice != 4);
	return false;
}


void user::print(ostream& os) {

	cout << "\nName of this account is: "<<nameofuser << endl;
	cout << "The total balance of accounts is: " << account::balance << endl;
	cout << "The balance of trust account is: " << trust::balance << endl;
	cout << "The balance of saving account is: " << saving::balance << endl;
	cout << "Thank you for using our bank\n" << endl;

};
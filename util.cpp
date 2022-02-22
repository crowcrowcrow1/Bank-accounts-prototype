#include "util.h"
#include<vector>
#include<iostream>
#include<string>
#include"account.h"

using namespace std;

void display(vector<user>&a) {
	for (auto i : a) {
		cout << i << endl;
	};


};
void deposit(vector<user>&a, double amount) {
	for (auto i : a) {
		if (i.deposit(amount)) {
			cout << "Deposite sucessful" << amount << "to" << i << endl;
		}

		else {
			cout << "failed"<<" amount " <<i ;
		}
	};
	

};
void withdraw(vector<user>&a,double amount) {
	for (auto i : a) {
		if (i.withdraw(amount)) {
			cout << "\nwithdrawed" << amount << "from " << i << endl;
		}
		else {
			cout << "\nfailed because no fund" << i << endl;
		}

	};



};

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

void displaysingle(vector<user>& accounts) {

	string name{ "" };
	bool check = false;
	cout << "Printing account names " << endl;
	display_reuse(accounts);
	cout << "Enter name " << endl;
	cin >> name;
	for (auto a : accounts) {
		if (a.nameofuser == name) {
			cout << a;
			check = true;
		}

	}
	if (check == false) {
		cout << "There is no matching account " << endl;
	}

}

void display_reuse(vector<user>& accounts) {
	for (auto a : accounts) {
		cout << a.nameofuser << endl;
	}
}
void deposit_single(vector<user>& accounts) {

	double deposit{ 0 };
	string name{ "" };
	bool check = false;

	cout << "\nDepositing " << endl;
	cout << "Printing account names " << endl;

	display_reuse(accounts);

	cout << "Enter amount " << endl;
	cin >> deposit;
	deposit = checking(deposit);

	cout << "Enter name " << endl;
	cin >> name;
	for (int i{ 0 }; i < accounts.size(); i++) {
		if (accounts[i].nameofuser == name) {
			accounts[i].deposit(deposit);
			check = true;
		}
	}
	if (check == false) {
		cout << "There is no match account" << endl;
	}

}

void account_creation(vector<user>& accounts) {
	double bal{ 0 };
	string name{ "" };
	bool check = true;
	cout << "\nInitial balance: ";
	cin >> bal;

	bal = checking(bal);

	cout << "\nName of the account: ";
	cin >> name;
	for (auto a : accounts) {
		if (a.nameofuser == name) {
			
			cout << "Name is already being used" << endl;

			check = false;
		}
	}
	if (check == true) {
		accounts.push_back(user(name, bal));
		cout << "Account has been created" << endl;
	}
}
void withdraw_single(vector<user>& accounts) {

	double withdraw{ 0 };
	string name{ "" };
	bool check = false;

	cout << "\nWithdrawing " << endl;
	cout << "Printing account names" << endl;
	
	display_reuse(accounts);

	cout << "Enter amount" << endl;
	cin >> withdraw;
	withdraw = checking(withdraw);
	
	cout << "Enter name of account" << endl;
	cin >> name;
	for (int i{ 0 }; i < accounts.size(); i++) {
		if (accounts[i].nameofuser == name) {
			accounts[i].withdraw(withdraw);
			check = true;
		}
	}
	if (check == false) {
		cout << "There is no match account" << endl;
	}
}
#include "util.h"
#include<vector>
#include<iostream>
#include<string>
#include"account.h"

using namespace std;
bool finding_name1(vector<user>& accounts, string name);
int finding_name2(vector<user>accounts, string name);
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
	
	int location;

	location = finding_name2(accounts, name);

	if (location != 999) {
		accounts[location].deposit(deposit);
	}
	else {
		cout << "No match account is found" << endl;
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
	check = finding_name1(accounts, name);
	if (check == false) {
		accounts.push_back(user(name, bal));
		cout << "Account has been created" << endl;
	}
	else {
		cout << "Name is being used already" << endl;
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
	int location{ 0 };
	location = finding_name2(accounts, name);

	if (location != 999) {

		accounts[location].withdraw(withdraw);
	}
	else {
		cout << "There is no match account" << endl;
	}
}

bool finding_name1(vector<user>& accounts,string name) {
	for (auto i : accounts) {
		if (i.nameofuser == name) {
			return true;
		}
	}
	return false;

}


int finding_name2(vector<user>accounts,string name) {
	for (int i{ 0 }; i < accounts.size(); i++) {
		if (accounts[i].nameofuser == name) {
			return i;
		}
	}
	return 999;

}
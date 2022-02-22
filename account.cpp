#include "account.h"
#include<string>
#include<iostream>
using namespace std;

account::account(string n, double balance) :name{ n }, balance{ balance } {
	

};
bool account::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
		cout << "Withdrawing money from general account balance is " << balance << endl;
		return true;
	}
	else {
		cout << "Not enough fund" << endl;
		return false;
	}
	


}
bool account::deposit(double amount) {
	if (amount >= 0) {
		balance += amount;
		return true;
	}
	return false; 


}
void account::print(ostream& os) {
	cout << "this is account and balance and name are" << balance << " " << name << endl;


}
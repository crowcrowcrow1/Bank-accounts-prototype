#include "saving.h"
#include"account.h"
#include"printing.h"
#include<iostream>
#include<string>
using namespace std;


saving::saving(string name , double balance, double inrate ):
	name{ name }, balance{ balance }, irate{ inrate }, account{ name}{
	
}
	
bool saving::withdraw(double amount) {
	if (amount <= account::balance) {
		balance -= amount;
		cout << "Withdrawing money from saving account balance is " << balance << endl;
		return account::withdraw(amount);
	}
	else {
		cout << "Not enough fund" << endl;
		return false;
	}
	
}
bool saving::deposit(double amount) {
	amount = amount + (amount * irate);
	balance += amount;
	return account::deposit(amount);
}

void saving::print(ostream& os) {
	cout << "this is saving account and name blanace rate are: " << name << balance << irate << endl;
}
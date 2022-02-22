#include "trust.h"
#include"saving.h"
#include<iostream>
using namespace std;

trust::trust(std::string n, double balance):saving{n},name{n},balance{balance}
{
	
};
bool trust :: withdraw(double amount) {
	if (limit >0 &&amount<=balance) {
		balance -= amount;
		limit--;
		cout << "Withdrawing money from trust account balance is " << balance << endl;
		return account::deposit(amount);
		
		
	}
	else {
		cout << "Not enough fund" << endl;
		return false;
	}

};
bool trust::deposit(double amount) {
	balance += amount;
	return account::deposit(amount);
	
	
};

void trust::print(ostream& os) {
	cout << "this is trust account name balance limit are" << name << balance<<"  " << limit << endl;


};
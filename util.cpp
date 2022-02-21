#include "util.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;

void display(vector<user>&a) {
	for (auto i : a) {
		cout << i << endl;
	};


};
void deposite(vector<user>&a, double amount) {
	for (auto i : a) {
		if (i.deposite(amount)) {
			cout << "deposited" << amount << "to" << i << endl;
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

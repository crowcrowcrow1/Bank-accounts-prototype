#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"user.h"

using namespace std;

void display(vector<user>&a);
	 void deposit(vector<user>&a,double amount) ;
	 void withdraw(vector<user>&a, double amount) ;
	 void menu();

	 double checking(double a);
	 void displaysingle(vector<user>& accounts);
	 void display_reuse(vector<user>& accounts);
	 void deposit_single(vector<user>& accounts);

	 void account_creation(vector<user>& accounts);
	 void withdraw_single(vector<user>& accounts);
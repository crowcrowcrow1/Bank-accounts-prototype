#pragma once
#include<string>
#include<iostream>
#include"printing.h"
class account:public printing
{
private:
	static constexpr const char* defualtname = "default account";
	static constexpr const double defaultbalance = 0.0;
protected:
	std::string name;
	double balance;
public:
	account(std::string n=defualtname, double balance=defaultbalance);
	virtual bool withdraw(double amount) = 0;
	virtual bool deposite(double amount) = 0;
	virtual ~account() = default;
	virtual void print(ostream& os)override;
};


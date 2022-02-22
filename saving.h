#pragma once
#include"account.h"
#include"printing.h"
#include<iostream>
#include<string>
using namespace std;
class saving:public account
{
private:
	static constexpr const char* defualtname = "saving default";
	static constexpr const double defaultbalance = 0.0;
	static constexpr const double interestrate = 0.05;
protected:
	string name;
	double balance;
	double irate;
public:
	saving(std::string name = defualtname, double balance = defaultbalance,double inrate=interestrate);
	virtual bool withdraw(double amount) override;
	virtual bool deposit(double amount) override;
	virtual ~saving() = default;
	virtual void print(ostream & os)override;


};


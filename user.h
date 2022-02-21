#pragma once
#include<string>
#include<iostream>
#include"checking.h"
#include"trust.h"
#include"printing.h"
using namespace std;


class user :virtual public checking, virtual public trust, virtual public printing 
{
private:
	static constexpr const char* defualtname = "default user account";
	static constexpr const double defaultbalance = 0.0;
protected:
	
	double balance=account::balance;
public:
	std::string name;
	user(std::string n = defualtname, double balance = defaultbalance);
	virtual bool withdraw(double amount) override;
	virtual bool deposite(double amount) override;
	virtual ~user() = default;
	virtual void print(ostream& os)override;
};

 





#pragma once
#include"saving.h"
#include<iostream>

class trust:public saving
{
private:
	static constexpr const char* defualtname = "default trust";
	static constexpr const double defaultbalance = 0.0;
	static constexpr const double limitone = 4;
protected:
	
public:
	std::string name;
	double balance;
	double limit{ limitone };
	trust(std::string n = defualtname, double balance = defaultbalance);
	virtual bool withdraw(double amount)override;
	virtual bool deposit(double amount) override;
	virtual ~trust() = default;
	virtual void print(ostream & os)override;
};


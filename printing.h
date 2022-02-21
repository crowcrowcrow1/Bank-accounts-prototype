#pragma once
#include<iostream>
using namespace std;
class printing
{
	friend ostream& operator<<(ostream& os, printing& a);
public:
	virtual void print(ostream& os) = 0;

};


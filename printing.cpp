#include "printing.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, printing& a)  {
	a.print(os);
	return os;

}

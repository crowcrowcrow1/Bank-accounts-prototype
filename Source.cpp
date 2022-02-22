#include<iostream>
#include<vector>
#include<string>

#include"account.h"
#include"saving.h"
#include"trust.h"
#include"util.h"
#include"user.h"


using namespace std;





int main() {
	int choice{ 0 };
	
	
	vector<user>accounts;
	
	 
	cout << "Welcome to Crow's bank! " << endl;
	
	do {
		menu();
		cin >> choice;
		if (choice == 1) {
			account_creation(accounts);
		}
		
		else if (choice == 2) {
			withdraw_single(accounts);

		}
		else if (choice == 3) {
			deposit_single(accounts);


		}
		else if (choice == 4) {
			cout << "\nBye !" << endl;
			return 0;
		}


		else if (choice == 5) {

			displaysingle(accounts);
		}

		else if (choice == 6) {
			display(accounts);
		}

		else {
			cin.clear();
			cin.ignore();
			cout << "Wrong input " << endl;
			cin >> choice;
		}

		
	} while (choice != 4);

	
	return 0;
	
}


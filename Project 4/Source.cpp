#include<iostream>
#include<string>
#include<iomanip>
#include"Classes.h"
using namespace std;

//Written by Kemelbek Tashkulov, IIT

//*******************************************************************************************
//This code has one function which is just the main()                                       *
//The point of this code is to create an account that can deposit/withdrawal using classes. *
//*******************************************************************************************

int main()
{

	//Account class
	account acc;
	
	//Intialization of the different variables needed
	string username;
	string acusername;
	string password;
	string acpassword;
	
	int choice;
	

	double balance = 0;
	double interesttotal = 0;
	//The amount array is used for the total amount deposited and withdrawn
	//amount[0] is for total deposited
	//amount[1] is for the toal withdrawn
	double amount[2] = { 0, 0 };


	cout << "Welcome to CNC! (The Chicago National Corporation) \n";
	cout << "----------------------------------------------------------------\n";
	cout << "Please enter your username please! \n";

	//Format for the output to be limited to only $0.00, two decimal points.
	cout << setprecision(2) << fixed << showpoint;
	cin >> username;
	//uses the account class to set the username
	acc.setusername(username);
	acusername = acc.getusername();
	
	
	
	cout << "Thank You! Now, please enter your password, please! \n";
	cin >> password;
	//uses the account class to set the password
	acc.setpassword(password);
	acpassword = acc.getpassword();

	cout << "Thank you for setting up your account. How much would you like to put into this account? \n";
	cin >> balance;
	//usses the account class to set the starting balance
	acc.setbalance(balance);
	balance = acc.getbalance();
	
	//With the new account set up, the if statement then determines if it is correct.
	if (username == acusername && password == acpassword)
		cout << endl << endl;
		cout << "Credentials accepted. Welcome, " << username << "! \n";
		cout << "*************************************************** \n";
		cout << "Current Balance: $" << balance << endl;

	//While loop used to create the menu of the account
	while (username == acusername && password == acpassword)
	{
		cout << "Please make a choice \n";
		cout << "1.Deposit \n";
		cout << "2.Withdrawal \n";
		cout << "3.Exit \n";
		cin >> choice;

		//while loops used to catch input errors.
		//Input is only allowed to be an int 1-3.
		while (cin.fail())
			{
				cin.clear();
				cin.ignore();
					cout << "ERROR WRONG INPUT. \n";
			}
		while (choice < 1 || choice > 3)
		{
			cout << "Please enter option within acceptable range (1-3). \n";
			cin >> choice;
		}
		
		//Switch statements used for the different choices in the menu 
		switch (choice)
		{
		
		//Case 1 is the choice to deposit.
		case 1: {cout << "How much would you like to deposit? \n";
			cin >> amount[0];
			//Amounts less than 0 are not allowed
			if (amount[0] < 0)
			{
				cout << "Negative entries are not allowed \n";
				system("pause");
				return 0;
			}
			
	
			balance += amount[0];
			
			//Each deposit triggers the interest class
			//The interest class then calculates the total interest accrued and adds it onto the balance
			interest interestmath(balance);
			interesttotal += interestmath.getInterestaccrued();

			//Output
			cout << "Balance: $" << balance << endl <<
			"Amount Withdrawn: $" << amount[1] << endl << 
			"Amount Deposited: $" << amount[0] << endl <<
			"Interest Accrued: $" << interesttotal << endl;

			
		} break;

		//Case 2 is the choice to withdrawal
		case 2: {cout << "How much would you like to withdrawal? \n";
			cin >> amount[1]; 
			
			//Withdrawing more than the balance is not allowed
			if (balance < amount[1])
			{
				cout << "Insufficient Funds. \n";
				system("pause");
				return 0;
			}
			//Withdrawing less than 0 is not allowed
			if (amount[1] < 0)
			{
				cout << "Negative entries are not allowed \n";
				system("pause");
				return 0;
			}
			
			balance -= amount[1];

			//Each withdrawal triggers the interest class
			//The interest class then calculates the total interest accrued and adds it onto the balance
			interest interestmath(balance);
			interesttotal += interestmath.getInterestaccrued();
			
			//Output
			cout << "Balance: $" << balance << endl <<
				"Amount Withdrawn: $" << amount[1] << endl <<
				"Amount Deposited: $" << amount[0] << endl <<
				"Interest Accrued: $" << interesttotal << endl;

		} break;

		//Case 3 is the choice to exit out of the program
		case 3: {return 0;} break;

		//Not default case needed due to the reason that only inputs of 1-3 are allowed
		}
	}


	system("pause");
	return 0;

}
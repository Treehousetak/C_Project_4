#pragma once
#include<string>
using namespace std;

//This code has to different classes being the account class and the interest class

//***************************************************************************
//The account class helps to set up the bank account for the user.          *
//This includes setting up the username,password, and the starting balance. *
//***************************************************************************


class account
{
//The username, password, and balance are protected so they do not change
protected:
	string username;
	string password;
	double balance;
public:
	//intializations

	account() {
		username = "user";
		password = "password";
		balance = 0;
	}
	
	//Sets the variables
	void setusername(string u)
	{username = u;}
	void setpassword(string p)
	{password = p;}
	void setbalance(double b)
	{balance = b;}

	//Returns the variables
	string getusername()
	{return username;}
	string getpassword()
	{return password;}
	double getbalance()
	{return balance;}
};


//******************************************************************************
// The interest class has the job of calculating the interest for the account. *
// The interest rate is 1% which is just 0.01                                  *
//******************************************************************************


class interest
{
private:
	double interestaccrued;
public:

	//calculations
	interest(double &balance)
	{
		//Interest rate multiplied by the balance to get the total interest gained
		interestaccrued = balance * 0.01;
		balance += interestaccrued;
	}
	//return the variable
	double getInterestaccrued()
	{return interestaccrued;}
};
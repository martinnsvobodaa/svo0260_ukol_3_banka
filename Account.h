#pragma once
#include "Client.h"

class Account
{
private:
	static int objectsCount;
	static int defaultInterestRate;

	int number;
	double balance;
	double interestRate;

	Client *owner;
	//Client* partner;

public:
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	//Account(int n, Client* c, Client* p);
	//Account(int n, Client* c, Client* p, double ir);

	~Account();
	int GetObjectsCount();
	void Report();
	void SetDefaultInterestRate(double rate);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	//Client* GetPartner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
};


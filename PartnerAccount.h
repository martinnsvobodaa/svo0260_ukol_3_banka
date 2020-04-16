#pragma once
#include "Account.h"
#include "Client.h"
#include "Bank.h"



class PartnerAccount : public Account
{
private:
	Client *partner;

public:
	PartnerAccount(int n, Client *c, Client *p);
	PartnerAccount(int n, Client *c, Client *p, double ir);
	~PartnerAccount();

	Client* GetPartner();
};


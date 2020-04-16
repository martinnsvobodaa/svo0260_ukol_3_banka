#include "PartnerAccount.h"

Client* PartnerAccount::GetPartner() {
    return this->partner;
}

PartnerAccount::~PartnerAccount() {
    
}

PartnerAccount::PartnerAccount(int n, Client *c, Client *p) : Account(n, c) {
   
    this->partner = p;

}

PartnerAccount::PartnerAccount(int n, Client *c, Client *p, double ir) : Account(n, c, ir) {
    
    this->partner = p;
    
}

#include "Account.h"

int Account::defaultInterestRate = 1.5;

void Account::SetDefaultInterestRate(double rate) {
    Account::defaultInterestRate = rate;
}

int Account::objectsCount = 0;

int Account::GetObjectsCount() {
    return Account::objectsCount;
}

Account::~Account() {
    this->owner = nullptr;
    //this->partner = nullptr;
}

Account::Account(int n, Client* c) {
    this->number = n;
    this->owner = c;
  //  this->partner = nullptr;
    this->balance = 0;
    this->interestRate = Account::defaultInterestRate;

    Account::objectsCount += 1;
}
Account::Account(int n, Client* c, double ir) {
    this->number = n;
    this->owner = c;
   // this->partner = nullptr;
    this->balance = 0;
    this->interestRate = ir;

    Account::objectsCount += 1;
}

/*Account::Account(int n, Client* c, Client* p) {
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->balance = 0;
    this->interestRate = Account::defaultInterestRate;

    Account::objectsCount += 1;
}
Account::Account(int n, Client* c, Client* p, double ir) {
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->balance = 0;
    this->interestRate = ir;

    Account::objectsCount += 1;
}
*/
int Account::GetNumber() {
    return this->number;
}
double Account::GetBalance() {
    return this->balance;
}
double Account::GetInterestRate() {
    return this->interestRate;
}
Client* Account::GetOwner() {
    return this->owner;
}
/*Client* Account::GetPartner() {
    return this->partner;
}*/
bool Account::CanWithdraw(double a) {
    if (this->GetBalance() >= a) {
        return true;
    }
    return false;
}

void Account::Deposit(double a) {
    this->balance = balance + a;
}
bool Account::Withdraw(double a) {
    if (this->CanWithdraw(a)) {
        this->balance =balance - a;
        return true;
    }
    return false;
}
void Account::AddInterest() {
    this->balance += this->balance * (this->interestRate / 100);
}

void Account::Report() {
    cout << this->GetNumber() << " "
        << this->GetBalance() << " "
        << this->GetOwner()->GetName()
        << endl;
}
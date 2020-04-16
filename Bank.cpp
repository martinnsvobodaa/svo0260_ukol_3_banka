#include <iostream>
#include "Bank.h"


using namespace std;

Bank::Bank(int c, int a) {
    this->clientsCount = c;
    this->accountsCount = a;

    this->clients = new Client * [c];
    for (int i = 0; i < this->clientsCount; i++) {
        this->clients[i] = nullptr;
    }
    this->accounts = new Account * [a];
    for (int i = 0; i < this->accountsCount; i++) {
        this->accounts[i] = nullptr;
    }

}

Bank::~Bank() {
    for (int i = 0; i < this->clientsCount; i++) {
        delete this->clients[i];
    }

    for (int i = 0; i < this->accountsCount; i++) {
        delete this->accounts[i];
    }
}

Client* Bank::GetClient(int c) {
    for (int i = 0; i < this->clientsCount; i++) {
        if (this->clients[i] != nullptr &&
            this->clients[i]->GetCode() == c) {
            return this->clients[i];
        }
    }
    cout << "Not Found" << endl;
    return nullptr;
}

Account* Bank::GetAccount(int n) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] != nullptr &&
            this->accounts[i]->GetNumber() == n) {
            return this->accounts[i];
        }
    }
    cout << "Not Found" << endl;
    return nullptr;
}

Client* Bank::CreateClient(int c, string n) {
    for (int i = 0; i < this->clientsCount; i++) {
        if (this->clients[i] == nullptr) {
            // Create new client
            Client* client = new Client(c, n);
            this->clients[i] = client;
            return client;
        }
    }
    cout << "Plna kapacita klientu" << endl;
    return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] == nullptr) {
            // Create new account
            Account* acc = new Account(n, c);
            this->accounts[i] = acc;
            return acc;
        }
    }
    cout << "Plna kapacita uctu" << endl;
    return nullptr;
}

Account* Bank::CreateAccount(int n, Client* c, double ir) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] == nullptr) {
            // Create new account
            Account* acc = new Account(n, c, ir);
            this->accounts[i] = acc;
            return acc;
        }
    }
    cout << "Plna kapacita uctu" << endl;
    return nullptr;
}

PartnerAccount* Bank::CreateAccount(int n, Client *c, Client *p) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] == nullptr) {
            // Create new account
            PartnerAccount* acc = new PartnerAccount(n, c, p);
            this->accounts[i] = acc;
            return acc;
        }
    }
    cout << "Plna kapacita uctu" << endl;
    return nullptr;
}

PartnerAccount* Bank::CreateAccount(int n, Client *c, Client *p, double ir) {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] == nullptr) {
            // Create new account
            PartnerAccount* acc = new PartnerAccount(n, c, p, ir);
            this->accounts[i] = acc;
            return acc;
        }
    }
    cout << "Plna kapacita uctu" << endl;
    return nullptr;
}

void Bank::AddInterest() {
    for (int i = 0; i < this->accountsCount; i++) {
        if (this->accounts[i] != nullptr) {
            this->accounts[i]->AddInterest();
        }
    }
}
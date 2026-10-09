#include<iostream>

using namespace std;

// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

/*
-> Invarient : Koi Bhi esa rule or fact jo kisi class ke liye hamesa true hoga. so it is called class
Invarient.

-> Class Invarient Rule ye kheta hain ki hamare pass ek class Parent hain , ye parent class kisi 
rule (r1) or invarient ko follow kar rahe hain, so according to rule , Jo Bhi es Parent class 
ki child class hogi , toh uske child ki responsibility hogi ki woh apne parent ke rule(Invarient) ko 
strengthen kare , ya as it is follow kare. but isko weak na kare.
-> If Child Class , Parent class ke Invarient rule ko break kar dete hain , toh hum khange it is not 
following this Invarient Rule , so it also breaks LSP.

*/

//Invariant : Balance cannot be negative
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }
    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

//Brakes invariant : Should not be allowed.
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        balance -= amount; // LSP break! Negative balance allowed
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
      // So it breaks the rule of Parent Invarient , it also supports Negative balance 
      // so it breaks the rule of class Invarient 
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
}

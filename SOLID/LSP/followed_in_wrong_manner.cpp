#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;
/* LSP : Liskov Substitution Principle 
-> SubClases should be Substitutable for their base classes. or this is called Inheritance
-> Means if we have Class A has class B as children 
so if client or some component ask to use Base Class or Parent Class if we pass his children class 
instead Parent class so it will be valid. 
-> Because children has all properties to exact their parent or because children extends its parent 
properties .
-> Kahi Bhi agar hum parent class ka object bhek sakte hain toh hum us parent ki jagah uski children 
class ka bhi object hej sakte hain.

** Example : 
Parent A 
Children B

methods of A : m1 , m2 ,m3 
methods of B : m4,m5 

suppose this is client code 
randomMethod(A*a) {
    a->m1();
    a->m2();
    a->m3();
}
so now how client call this funciton 
 -> A* a = new A();
 Instead of Using its Parent 
 We can use 
 -> A* a = new B(); // now this object has reference of Object B
*/
class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;

public:
    CurrentAccount() { 
        balance = 0; 
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedTermAccount : public Account {
private:
    double balance;

public:
    FixedTermAccount() { 
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

//Client class
class BankClient {
private:
    vector<Account*> accounts;

public:
    BankClient(vector<Account*> accounts) { 
        this->accounts = accounts; 
    }

    void processTransactions() {
        for (Account* acc : accounts) {
            acc->deposit(1000);

            //Checking account type explicitly
            if (typeid(*acc) == typeid(FixedTermAccount)) {
                cout << "Skipping withdrawal for Fixed Term Account.\n";
            } else {
                try {
                    acc->withdraw(500);
                } catch (const logic_error& e) {
                    cout << "Exception: " << e.what() << endl;
                }
            }
        }
    }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions();

    return 0;
}

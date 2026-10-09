#include<iostream>

using namespace std;

/*

IMMUTABLE CLASS : 
-> Ek Ese class jisko koi inherit na kar sake.
-> Means It can not be changes

IMMUTABLE METHODS : 
-> Ek Ese Methods jisko koi change na kar sake.
-> Ese Methods jinko koi override na kar sake.

to Make IMMUTABLE ANYTHING : Use final for clas or methods 

*/

// Sub class methods should not be allowed state changes What
// Base class never allowed.
/*

-> History Constraints said that ki History Kabhi change nahi honi chaiye.
-> Means Ek Baar Jo Parent class ne khe diya ki ye state hain , toh uska child us state ko change
nahi kar sakta hain. balki uski responsibilty hain ki woh uske state ko follow kare.
-> History Constraint koi method nahi hain , balki yeh ek constraint hain jo us class ko follow 
karna hain, and usko koi change na kare.
-> Is History constraints of Parent ko uska child bhi break nahi kar sakta hain
*/
class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative");
        balance = b;
    }

    // History Constraint : Withdraw should be allowed
    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};
    

class FixedDepositAccount : public BankAccount {
public:
    FixedDepositAccount(double b) : BankAccount(b) {}

    // LSP break! History constraint broke!
    // Parent class behaviour change : Now withdraw is not allowed.
    //This class will brake client code that relies on withdraw.
// Now child break the constraints. so it breaks History constraints of parent class.
    void withdraw(double amount) override {
        throw runtime_error("Withdraw not allowed in Fixed Deposit");
    }
};
    
int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(100);
}

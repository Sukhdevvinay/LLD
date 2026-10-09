
#include <iostream>

using namespace std;

/*

-> Pre_Condition : Ye koi bhi ek ese condition hoti hain jo kise method ke execute hone se phele 
execute ya run hone se phele follow hone chaiye.

-> Toh Agar Kisi Parent ke method par koi pre condition lagi wayi hain , toh uske child jo us 
parent ko inherit karta hain, toh woh us pre condition ko weak kar sakte hain , but strengthen 
nahi kar sakte hain.

-> EXAMPLE : 
Parent ke method ke uppar condition is : password.length < 8 
so uska 
Child ka method us main condition ko : weak kar sakta hain , like , password < 6 but not > 6 
if greater than 6 , then our parent condition is break 
if less than 6 , then parent condition is also followed.
so greater wala break Pre-condition rule so it also breaks LSP.

*/
// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.

/
class User {
public:
    // Precondition: Password must be at least 8 characters long
    virtual void setPassword(string password) {
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

class AdminUser : public User {
public:
    // Precondition: Password must be at least 6 characters
    void setPassword(string password) override {
        if (password.length() < 6) { 
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout << "Password set successfully" << endl;
    }
};

int main() {
    User* user = new AdminUser();
    user->setPassword("Admin1");  // Works fine: AdminUser allows shorter passwords

    return 0;
}

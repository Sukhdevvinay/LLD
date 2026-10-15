#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = new Singleton();
/*
Toh Ab humne static member main hi object create kar diya , toh isse ye hoga ki main function run 
hone se phele hi static member main created object ka refernce aa jayega , in another word 
new object create ho gaya hain.
toh ab jab bhi kitne bar bhi object create kar lo toh hume same instance milega.

** DRAWBACK : 
-> Singleton class is expesive due to high memory resources that is used in the creation of that class.
-> It waste memory.

** PRACTICAL USECASE : 
-> Logging System
-> Database connection
-> Configuration Manager.
*/

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}

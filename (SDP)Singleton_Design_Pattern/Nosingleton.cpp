#include<iostream>

using namespace std;

/*
*** SDP ****
SINGLETON CLASS or SINGLETON : Ye ek special tarah ki class hoti hain jiska hum sirf ek hi object
create kar sakte hain.
SINGLETON CLASS -> 
* Ye yeh kahte hain ki Imagine karo ye ki ek ese class hain jiska hum sirf ek hi object create kar sakte
hain or ek hi instance create kar sakte hain.
* Agar Humne Uska dobare Object create karne ki kosis ki toh phele wala hi object or instance return kar 
dege.
* Ya Ek ese Class Jiske Multiple Objects Create Nahi Ho sakte hain.
* So Isko Implementation Ko Hum SDP Khete hain.
* Toh Hume ek ese class banane hi jiska object hum sirf ek bar hi create kar sakte hain , agar hum 
usko object dobare banane ki kosis kare toh woh hume phele wala object return kar de. 
*/
class NoSingleton {
public:
    NoSingleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main() {
    NoSingleton* s1 = new NoSingleton();
    NoSingleton* s2 = new NoSingleton();

    cout << (s1 == s2) << endl; // op is 0 
    /*
        Because both pointer points to two different addresses in the heap Memory.
        What cause to make two different addreses
        * Jab Bhi Hum New Keyword use karte hain toh constructor call hota hain toh ek new 
        object ban jata hain.
        * Toh jab bhi hum object create kar rahe hain toh ye bar bar use constructor ko use 
        karke ek new object create kar deta hain.

        for Next Follow next file.
    */
}

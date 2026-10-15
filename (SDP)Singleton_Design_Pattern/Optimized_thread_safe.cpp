#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    // Double check locking..
    static Singleton* getInstance() {
        if (instance == nullptr) {  // First check (no locking)
            lock_guard<mutex> lock(mtx);  // Lock only if needed
            if (instance == nullptr) {  // Second check (after acquiring lock)
              /*
              Second check hum esliye kar rahe hain , beacuse let us suppose jab ek sath 2 threads
              instance == nultr main aye toh unme se ek ko sirf lock acquire ho ga and 2nd wait karege
              lock hatna ko toh ab 1st thread ne ek object create kar diya and lock hata diya. 
              bhale hi ek object create ho gaya hain toh ab jab 2nd thread ka lock hata toh woh phir 
              se ek new object create kar dege , so to avoid this better to check same condition again 
              to overcome two object creation.
              */
                instance = new Singleton();
            }
        }
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}

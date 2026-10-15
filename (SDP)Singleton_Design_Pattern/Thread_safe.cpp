#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx; // it helps to do lock or unlock threads of crtical section of code.

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Lock for thread safety
/* Now Ab isme jab lock lag gaye toh iske niche wala section main sirf ek hi thread enter karege 
  ya ab is pure area main sirf ek hi thread enter karege. toh ab sirf ek hi bar object banaga sirf.
*/
        if (instance == nullptr) {
            instance = new Singleton();
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

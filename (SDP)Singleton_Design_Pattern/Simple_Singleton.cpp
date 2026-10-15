#include<iostream>

using namespace std;
/* WE SOLVE USING PRIVATE KEYWORD OF DECLARATION OF OBJECTS*/
/*
Toh Jaise Hi humne constructor ko private declare kara , toh ab object create karna accessable nahi 
raha , because it is private declared. means ab hum object declare nahi kar sakte hain.

*/
class Singleton {
private:
   static Singeton* instance;
    Singleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
public:
  static Singleton* getInstance() { // Toh yeh hame ek pointer lake dege Singleton class ka
    if(instance == nullptr) instance = new Singleton();
    return instance;
  }
};

/*
STATIC METHOD : 
* These type of Methods belong to class not objects.
* So toh hume ese call karne ke liye hume us class ka name + method name likhna hoga na ki us objetc 
ka name
* Ye Jo Method hote hain , woh all object ke liye same rahete hain, means har object use call karpayege
using class name.
STATIC VARIABLE : 
* These type of Variables belong to class not objects.
* So toh hume ese call karne ke liye hume us class ka name + method name likhna hoga na ki us objetc 
ka name
* Ye Jo Variables hote hain , woh all object ke liye same rahete hain, means har object use call karpayege
using class name
* Means it is same for all objects of same class only.
*/
Singleton* Singleton :: instance = nullptr; // static member
int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl; // now op is 1
}

/*
DRAWBACK OF THIS METHOD : 
-> It is not thread safe.
-> Multiple thread can create two objects at same time.
*/

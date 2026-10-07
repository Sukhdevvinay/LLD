
#include <iostream>

using namespace std;

// Method Argument Rule : 
// Subtype method arguments can be identical or wider than the supertype
// C++ imposes this by keeping singature identical
/*
 Broad or Broader Class : Parent Class 
 Narrow or Narrow Class : Child Class

 -> Animal is Broader class of Dog class
 -> Dog is Narrow class of Animal class

**** Example **** 
class Parent {
void solve(string s) {}
}
class Child : public Parent {
void solve(string z) {} 
// toh ye jo child ke method ke andar jo argument hum pass kar rahe hain usme ya toh uska parent class
ya broder class ko pass kar sakte hain
// means string z ke parent ko yaha pass kar sakte hain.
}
 
*/
class Parent {
public:
    virtual void print(string msg) {
        cout << "Parent: " << msg << endl;
    }
};

class Child : public Parent {
public:
    void print(string msg) override { 
        cout << "Child: " << msg << endl;
    }
};

//Client that pass string as msg as client expects.
class Client {
private:
    Parent* p;

public:
  Client(Parent* p) {
        this->p = p;
    }  
    void printMsg() {
        p->print("Hello");
    }
};

int main() {

    Parent* parent = new Parent();
    Parent* child = new Child();

    //Client* client = new Client(parent);
    Client* client = new Client(child);

    client->printMsg();


    return 0;
}

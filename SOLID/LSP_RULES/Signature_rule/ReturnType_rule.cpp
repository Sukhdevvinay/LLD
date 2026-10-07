#include <iostream>

using namespace std;

// Return Type Rule : 
// Subtype overriden method return type should be either identical 
// or narrower then the parent method's return type.
// This is also called as return type covariance.
// C++ enforces this by covariance.
/*

*/
class Animal {
    //some common Animal methods
};

class Dog : public Animal {
    //Additional Dog methods specific to Dogs.
};


class Parent {
public:
    virtual Animal* getAnimal() { 
        cout << "Parent : Returning Animal instance" << endl;
        return new Animal();
    }
};

class Child : public Parent {
public:
//  Can also have return type as Dog
    Animal* getAnimal() override {  
      /*
      Yaha Par is children class main is object ke narrow class rakh sakta hoon , means 
      iska main children bhi use kar sakta hoon , we can say we can use Dog* instead Animal 
      because yaha par narrowed classes are allowed to use , but use class ka parent nahi rakh
      sakta. only childrens.
      Beacuse kyuki ek parent class ka object ek child class ko point kar sakta hain.
      */
        cout << "Child : Returning Dog instance" << std::endl;
        return new Dog();
    }
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeAnimal() {
        p->getAnimal();
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(child);
    //Client * client = new Client(parent);
    client->takeAnimal();

    return 0;
}

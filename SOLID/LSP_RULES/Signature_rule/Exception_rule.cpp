#include <iostream>

using namespace std;
// Exception is a Object , and it has multiple objects or multiple children objects.
// Exception Rule:
// A subclass should throw fewer or narrower exceptions 
// (but not additional or broader exceptions) than the parent.
// C++ does not enforces this. Hence no compilation error.

/*
├── std::logic_error        <-- For logical errors detected before runtime // Parent and below are childs
│   ├── std::invalid_argument   <-- Invalid function argument
│   ├── std::domain_error       <-- Function argument domain error
│   ├── std::length_error       <-- Exceeding valid length limits
│   ├── std::out_of_range       <-- Array or container index out of bounds
│
├── std::runtime_error      <-- For errors that occur at runtime // Parent and below are childs
│   ├── std::range_error        <-- Numeric result out of range
│   ├── std::overflow_error     <-- Arithmetic overflow
│   ├── std::underflow_error   
*/

/*
Means Jo hamra pass object hain woh ya toh apne error object throw kar de and apne child class ki error objects
ko return kar de , but ye apne parent ke errors ke object ko throw na kare only children.

** Example 
-> Suppose Agar hamra parent usek kise method ke andar koi exception throw kar raha hain , jaise ki
hamra parent run time error throw karta hian.
-> Toh Is Parent ke child ke pass bhi woh method hoga , toh woh child us method ko override kar 
sakta hain , toh woh override karte samay sirf , in object ko use kar sakta hain like : 
* Ya toh woh use same exception ko use kare ya overide kare 
* Ya us exception ki child ko use kare , ya override kare 
* But Use Exception ke parent ko nahi kar sakte hain.

-> Now See 
* Parent Uses logic_error as exception 
* So ab Eska child ya toh same logic_error exception throw kar sakta hain , ya fir es exception 
ki child ko use kare 
* Like ye logic_error exception ke child out_of_range ko use kar sakta hain.
* Because out_of_range is a parent of logic_error
* So Ab Parent logic_error ko throw kar raha hain 
* Toh is Parent ka children ya toh same logic_error ko throw kar sakta hain , ya is logic_error
ki child ko throw kar sakta hain , means ye logic_error ki child menas out_of_range ko throw 
kar sakta hain.
*/ 
class Parent {
public:
    virtual void getValue() noexcept(false) { // Parent throws logic_error exception
        throw logic_error("Parent error");
    }
};

class Child : public Parent {
public:
    void getValue() noexcept(false)  override { // Child throws out_of_range exception
        throw out_of_range("Child error");
        // throw runtime_error("Child Error"); // This is Wrong
    }
    // noexcept(false) -> Means It will throw the Exception.
};

class Client {
private:
    Parent* p;

public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeValue() {
        try {
            p->getValue();
        }
        catch(const logic_error& e) {
            cout << "Logic error exception occured : " << e.what() << endl;
        }
        /*
        * Because this happens kyuki client expect logic_error as reference object 
        * So Agar hamara children us Parent ko override kare toh woh , yaha catch main 
        reference object e = logic_error hoga which is valid
        * Agar Us Parent Object ka children is logic_error ke child ko override kare toh 
        reference object e = child of logic_error exception
        so this is also valid.
        becuase 
        * reference object type is logic_error 
        * if we pass e as child of logic_error that is valid , if we pass parent of logic_error 
        so this is not valid 
        * Beacue 
          -- Parent can store child as reference : logic_error can hold -> out_of_range
          -- Child can not store Parent as reference :  logic_error can not hold : parent of logic_error
        */
    }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    //Client* client = new Client(child);

    client->takeValue();

    return 0;
}


#include <iostream>

using namespace std;

/*
FDP : 
-> Isse Phele hum client side par object create karte hain , or we create objects at the time of 
run time.
-> So Ab is pattern main hum , client side par ek ese class banayenge jo apne andar jakar ek new 
object classes banayga
-> Means hum different objects ko client par create nahi kareneg , hum sirf only one class banayenge 
called as Factory and woh factory class apne andar jakar new objects banayge.
-> Isme Hum Bussiness logic ko seprate kar rahe hain object create logic se 

*** SO OUR ARCHITECTURE IS LIKE : ***
-> Toh Hum ek seprate class banayenge jiske responsibility hoge new objects ko create karne ki.
-> So AB client Factory class ke pass jayege and ask for object creation 
-> Now Client is seprated from Object Creation.
-> So Now client Factory ko bolega ki mujhe object de , toh factory use object create karke dege.
-> Ab client ko nahi pata ki object kaise create ho rahe hain. woh sirf factory ko bolega ki object 
de toh use factory object lake dege.
-> Aim for this Application is that To decouple the Application and CLient from Object Creation.
*/

/*
SIMPLE FACTORY METHOD IS NOT A PATTERN , IT IS DESIGN PRINCIPLE.
*/

class Burger {
public:
    virtual void prepare() = 0;  // Pure virtual function
    virtual ~Burger() {}  // Virtual destructor
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();

    return 0;
}

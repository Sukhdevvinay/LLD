#include <iostream>

using namespace std;

/*
POST CONDITION : 

-> Ye Ek ese condition hoti hain , jo kise method ke run hone ke baad ya execute hone ke baad 
satisfy hote hain ya follow hoti hain.

-> Lets say we have one Parent , and is parent ke upar ek Post condition lagi hui hain. 
toh is parent ke child class iske parent ke post condition ko ya toh ese as it is follow kar le 
ya usko strengthen kar de. strengthen means constraints kar de.

-> EXAMPLE : 
* Parent class ke pas ek method hain which is break 
* so is method ko apply karne ke bad hamare car slow down ho jane chaiye after applying this method.
* lets parent ke method woh us speed ko decreased by 20 karte hain.
* Lest hamre pass es car class ka child electric car hain, toh woh jab is method ko inherit 
karege toh after applying break woh iske speed decrease karne chaiye na ki increase 
ya phir aur jayade rate se decrease kar de.
suppose parent class speeed decrease by 20 kar rahe hain.
toh child class speed decrease by 20 ho , but woh uski charging ko increase kar sakte hain.
so it strengthen the post condition of parent methods

so break ke baad speed increase kare toh it breaks LSP.

*/
// A Postcondition must be statisfied after a method is executed.
// Sub classes can strengthen the Postcondition but cannot weaken it.

class Car {
protected:
    int speed;    

public:
    Car() {
        speed = 0;
    }
    
    void accelerate() {
        cout << "Accelerating" << endl;
        speed += 20;
    }

    //PostCondition : Speed must reduce after brake
    virtual void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};

// Subclass can strengthen postcondition - Does not violate LSP
class HybridCar : public Car {
private:
    int charge;

public:

    HybridCar() : Car() {
        charge = 0;
    }

    // PostCondition : Speed must reduce after brake
    // PostCondition : Charge must increase.
    void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;
    }
};


int main() {
    Car* hybridCar = new HybridCar();
    hybridCar->brake();  // Works fine: HybridCar reduces speed and also increases charge.

    //Client feels no difference in substituting Hybrid car in place of Car.

    return 0;
}

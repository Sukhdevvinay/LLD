#include <iostream>
#include <stdexcept>

using namespace std;

/*
ISP : INTERFACE SEGREGATION PRINCIPLE 

* Many client Specific Interface are better then general purpose interface.
* Client Should not be forces to implement methods they don't need.

-> Means Bhot saare client specific interface banana hamese better hain then ek single client
interface se basically esse ye dikkat hoti hain ki jab hum us parent ki child class banate hain 
toh uske child ko kuch methods ese mil jate hain ,inheritance ke karan , 
jinka usko koi use nahi hain,

*** EXAMPLE 

->  if we make SHAPE as Single Interface and this interface has methods
which are following 
 * AREA() 
 * VOLUME()
 
and this child has many methods like squeare , rectangle , cube , so ab 
2d figures like square , rect ko bhi volume inherit karna hoga , due to inheritance 
so these figures have this method is useless

-> So better way is that to Make Multiple inteface as Dimensions 
  * 2D 
  * 3D 

so this is called ISP

>
*/
// Single interface for all shapes (Violates ISP)
class Shape {
public:
    virtual double area() = 0;
    virtual double volume() = 0; // 2D shapes don't have volume!
};

// Square is a 2D shape but is forced to implement volume()
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }

    double volume() override {
        throw logic_error("Volume not applicable for Square"); // Unnecessary method
    }
};

// Rectangle is also a 2D shape but is forced to implement volume()
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    double volume() override {
        throw logic_error("Volume not applicable for Rectangle"); // Unnecessary method
    }
};

// Cube is a 3D shape, so it actually has a volume
class Cube : public Shape {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};

int main() {
    Shape* square = new Square(5);
    Shape* rectangle = new Rectangle(4, 6);
    Shape* cube = new Cube(3);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try {
        cout << "Square Volume: " << square->volume() << endl; // Will throw an exception
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    return 0;
}

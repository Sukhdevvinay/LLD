#include <iostream>
#include <string>

using namespace std;

/*
Decorator Pattern : 

Let us Suppose hamare pass ek object hain , hum es object ko additional responsibility or additonality 
functionality provide kar rahe hain at runtime not compile time.
means Abhe jo ye kar raha hain toh ye kuch aur bhi kar sake aur iska kaam hum change kar sake at 
run time not compile time.

 Let us humne ek object banaya , Obj , and this object have one method that is do_something() 
 so jab hum ese call karte hain toh ye hume return karege "I Did Something" 
 toh hum chahte hain ye jo isne message return kara hain hum ese change kar sake at run time , 
 not compile time , 
 Like Hum ese change kar de like " I Did Something Great" or Any other message that we want.


 DEFINATION : 
 Decorator Pattern attaches additonal responsibilty to an object dynamically Decorator provides a 
 flexible alternate to subclassing for extending functionality.
 
*/
// Component Interface: defines a common interface for Mario and all power-up decorators.
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}  // Virtual destructor
};

// Concrete Component: Basic Mario character with no power-ups.
class Mario : public Character {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Charatcer and "has-a" Character.
class CharacterDecorator : public Character {
protected:
    Character* character;  // Wrapped component
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }

};

// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator {
public:
    HeightUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
    
};

// Concrete Decorator: Gun Shooting Power-Up.
class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }
};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }
    
    ~StarPowerUp() {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

int main() {
    // Create a basic Mario character.
    Character* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // Decorate Mario with a HeightUp power-up.
    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    // Decorate Mario further with a GunPowerUp.
    mario = new GunPowerUp(mario);
    cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    // Finally, add a StarPowerUp decoration.
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    delete mario;

    return 0;
}

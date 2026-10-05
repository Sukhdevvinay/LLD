#include <bits/stdc++.h>
using namespace std;
/*
SRP : Single Responsibilty Principle 
OCP : Open Close Principle 
LSP : Liskov Substitution Principle
ISP : Interface Segregation Principle
DIP : Dependency Inversion Principle
*/
 
/* SRP -> 
  * A class should have one reason to change
  * A class should do Only One thing. means only handle one responsibilty.
*/
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products; 

public:
    void addProduct(Product* p) { 
        products.push_back(p);
    }

    const vector<Product*>& getProducts() { 
        return products;
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase();

    return 0;
}

/*
If we dont follow design principles then what are issues that we face 

i) Maintainability : Easy to Integerate new Feature with small changes without new bugs.
ii) Readability : Easy to Understand 
iii) Bugs 

So to solve these we have to follow design principles.

*/

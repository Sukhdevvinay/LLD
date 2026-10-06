#include <iostream>
#include <vector>
/* OCP : OPEN CLOSE PRINCPLE 
-> A Should be Open for extenstion but close for modification. means 
-> Means Koi Bhi New feature ko add karne ke liye hum purane classes ke code ko change na kare
-> Means koi new feature banane ke liye koi purani classes ke andar jakar koi new method nahi likhe.

-> So to solve OCP principle we use these methods
* Abstraction 
* Inheritance 
* Polymorphism
>
-> Abstarct class : Is Class main Hum methods ko virtual banate hain means hum un methods ko virtual 
bana dete hain , means hum uske methods ko sirf declare karte hain , and unko define karne ka kaam un
classes ka hain jo us class ko inherit karenge,
*/
using namespace std;

// Product class representing any item in eCommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

//1. ShoppingCart: Only responsible for Cart related business logic.
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

    //Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartPrinter(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : cart->getProducts()) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << cart->calculateTotal() << endl;
    }
};

// 3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartStorage {
private:
    ShoppingCart* cart; 

public:
    ShoppingCartStorage(ShoppingCart* cart) { 
        this->cart = cart; 
    }

    void saveToSQLDatabase() {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
  // We add these two new feature to break OCP 
    void saveToMongoDatabase() {
        cout << "Saving shopping cart to Mongo DB..." << endl;
    }

    void saveToFile() {
        cout << "Saving shopping cart to File..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();

    return 0;
}

#include <iostream>
using namespace std;

/*

DIP : DEPENDENCY INVERSION PRINCIPLE 

-> High Level Module shoud not depend on low level module but rather both should depend on abstraction.
-> Means hamare pass ek high level module and low level module hain , toh kabhi bhi HLD or LLD direct 
ek dusre se interact na kare balki ye kise ek Abstraction layer or Interface ke through baat kare.

** Exampele ** 
-> Suppose we have one Application (APP , Website) 
toh Application is Our HLD module 
toh these database layer or API : LLD Module
so en done ke beech main hame ek interface bana hoga.

Below Example main ye dono direct baat kar rahe hain , it breaks DIP .

*/
class MySQLDatabase {  // Low-level module (It will Intract to SQL servives or database)
public:
    void saveToSQL(string data) {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDBDatabase {  // Low-level module (It will Interact to MONGO DB services)
public:
    void saveToMongo(string data) {
        cout << "Executing MongoDB Function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

class UserService {  // High-level module (Tightly coupled)
private:
    MySQLDatabase sqlDb;  // Direct dependency on MySQL
    MongoDBDatabase mongoDb;  // Direct dependency on MongoDB

public:
    void storeUserToSQL(string user) {
        // MySQL-specific code
        sqlDb.saveToSQL(user);  
    }

    void storeUserToMongo(string user) {
        // MongoDB-specific code
        mongoDb.saveToMongo(user);  
    }
};

int main() {
    UserService service;
    service.storeUserToSQL("Aditya");
    service.storeUserToMongo("Rohit");
}

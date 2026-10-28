#include <iostream>
using namespace std;

/*
Facade Design Pattern : 
Isme hum client ko directly kisi complex system se baat karane se bachate hain. because 
complex sub system andar se hi aapas main bahut complex hain agar hum usko directly client ko 
de de toh dikkat hogi.

So we introduce a Interface called Facade jisse client directly complex system se baat nahi karta hain 
balki woh ek facade class se baat karta hain , and woh facade class us complex system se baat karte hain 
ya we can say that woh facade class usse kam karwate hain.
toh sirf client us facade class ka method call karta hain that is do_work() , by using this client can
interact with complex subsystem.

DEFINATION : 
Facade Pattern provides a simplified , unified interface to a set of complex subsystem. It hides
the complexity of the system and exposes only what is neccessary.

DF BW FACADES , ADAPTER.
FACADES : Hides the Complexity 
ADPATER : To Make the interaction bw completly diff interface.
*/
// Subsystems
class PowerSupply {
public:
    void providePower() {
        cout << "Power Supply: Providing power..." << endl;
    }
};

class CoolingSystem {
public:
    void startFans() {
        cout << "Cooling System: Fans started..." << endl;
    }
};

class CPU {
public:
    void initialize() {
        cout << "CPU: Initialization started..." << endl;
    }
};

class Memory {
public:
    void selfTest() {
        cout << "Memory: Self-test passed..." << endl;
    }
};

class HardDrive {
public:
    void spinUp() {
        cout << "Hard Drive: Spinning up..." << endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: Booting CPU and Memory checks..." << endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load() {
        cout << "Operating System: Loading into memory..." << endl;
    }
};

// Facade
class ComputerFacade {
private:
    PowerSupply powerSupply;
    CoolingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;

public:
    void startComputer() {
        cout << "----- Starting Computer -----" << endl;
        powerSupply.providePower();
        coolingSystem.startFans();
        bios.boot(cpu, memory);
        hardDrive.spinUp();
        os.load();
        cout << "Computer Booted Successfully!" << endl;
    }
};

// Client
int main() {
    ComputerFacade computer;
    computer.startComputer();

    return 0;
}

#include <iostream>
#include <string>


/*
ADP : 
Jiase hamare pass ek US Socket hain and ek Indian Charrger hain , toh yeh dono aapas main connect nahi
ho sakte hain , toh inko aapas main connection banana ke liye ek interface or type of adapter 
jisse yeh dono appas main baat kar sake.

So ADP is type of class or interface jo two different classes ki bich main ek bridge bante hain or woh
interface bante hain, jisse ye dono aapas main communicate kar sake.

Real life problem : 

Jaise ki hamare application main existing code hain . toh hum kuch 3rd party ka existing code like
payment gateway or notification service code or any other 3rd party service. ko apne application main
integerate karte hain. 
so 3rd party services or library ka code different hoga hamare existing code se , means un dono ke 
under alag classes ka code likha hoga , toh hume ab in dono ke bich main interface likha hain jo 
in dono ko , communicate kara sake through this inteface , so we called a interface as Adapter.

DEFINATION : 
Adapter Converts the interface of a class into another interface that client expects. Adapter lets 
classes work together that could'nt otherwise because of incompatible interface.
*/
using namespace std;

// 1. Target interface expected by the client
class IReports {
public:
    // now takes the raw data string and returns JSON
    virtual string getJsonData(const string& data) = 0;
    virtual ~IReports() {}
};

// 2. Adaptee: provides XML data from a raw input
class XmlDataProvider {
public:
    // Expect data in "name:id" format (e.g. "Alice:42")
    string getXmlData(const string& data) {
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id   = data.substr(sep + 1);
        // Build an XML representation
        return "<user>"
               "<name>" + name + "</name>"
               "<id>"   + id   + "</id>"
               "</user>";
    }
};

// 3. Adapter: implements IReports by converting XML → JSON
class XmlDataProviderAdapter : public IReports {
private:
    XmlDataProvider* xmlProvider;
public:
    XmlDataProviderAdapter(XmlDataProvider* provider) {
        this->xmlProvider = provider;
    }

    string getJsonData(const string& data) override {
        // 1. Get XML from the adaptee
        string xml = xmlProvider->getXmlData(data);

        // 2. Naïvely parse out <name> and <id> values
        size_t startName = xml.find("<name>") + 6;
        size_t endName   = xml.find("</name>");
        string name      = xml.substr(startName, endName - startName);

        size_t startId = xml.find("<id>") + 4;
        size_t endId   = xml.find("</id>");
        string id      = xml.substr(startId, endId - startId);

        // 3. Build and return JSON
        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};

// 4. Client code works only with IReports
class Client {
public:
    void getReport(IReports* report, string rawData) {
        cout << "Processed JSON: "
        << report->getJsonData(rawData)
        << endl;
    }
};

int main() {
    // 1. Create the adaptee
    XmlDataProvider* xmlProv = new XmlDataProvider();

    // 2. Make our adapter
    IReports* adapter = new XmlDataProviderAdapter(xmlProv);

    // 3. Give it some raw data
    string rawData = "Alice:42";

    // 4. Client prints the JSON
    Client* client = new Client();
    client->getReport(adapter, rawData);
    // → Processed JSON: {"name":"Alice", "id":42}

    // 5. Cleanup
    delete adapter;
    delete xmlProv;
    return 0;
}

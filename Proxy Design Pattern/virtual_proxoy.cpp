#include<iostream>
#include<string>

/*
 To save the extra memory from directly creating all expensive steps at the time of creating 
 the objects. and if client is not ask the method of display then our memory is useless.
 So Better is that create the object when client calls the method to display the image 
 so when user calls the method to display the image then we create the object of display and when 
 we create this object so all 4 expensive steps will be executed now we save the memory from wasting 
 memory. because no memory wastage because we create these steps when client calls that expensive 
 method 

 so in this we save the wastage of memory
*/
using namespace std;

class IImage { 
public:
    virtual void display() = 0;
    virtual ~IImage() = default;
};

class RealImage : public IImage {
    string filename;
public:
    RealImage(string file) {
        this->filename = file;
        // Heavy Operation
        cout << "[RealImage] Loading image from disk: " << filename << "\n";
    }

    void display() override {
        cout << "[RealImage] Displaying " << filename << "\n";
    }
};
    
class ImageProxy : public IImage {
    RealImage* realImage;
    string filename;
public:
    ImageProxy(string file) {
        this->filename = file;
        realImage = nullptr;
    }

    void display() override {
        // Lazy initialization of RealImage
        if (!realImage) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {

    IImage* image1 = new ImageProxy("sample.jpg");
    image1->display();

    
}

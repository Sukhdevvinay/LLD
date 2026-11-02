#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/*
Koi Bhi Problem statement jisse hum hirrichel ya trees ki form main express kar sakte hain . 
means usme 2 tarah ke nodes hote hain like as leaf nodes and Intermediadate nodes.

Koi Bhi Problem jisme hum use different-different compoent main express kar sakte hain ya tree like 
structure main represent kar sakte hain , so it is solved by this Design Pattern (CDP).
Example : Design a Folder System

                          FILE_SYSTEM 
                              |
                    -----------------------
                    |                      |
                  Folders                 Files 
                    |                       
              ------------                 
              |           |                      
            Folders      Files         

ls() -> Isme Us Sirf folder ki directory main jo elements present woh print hota hain , means 
sirf uske children print hote hain na ke us folder/file ke parents.
openAll() -> Isme Sabhi Chije print ho jate hain from Top to Bottom.

DEFINATION : 
Composite Pattern Composes Object into tree like structure reperensenting a part whole hierrarchy. 
It let client treats individual object and composition of object uniformly.
*/
// Base interface for files and folders
class FileSystemItem {
public:
    virtual ~FileSystemItem() {}
    virtual void ls(int indent = 0) = 0;            
    virtual void openAll(int indent = 0) = 0;      
    virtual int getSize() = 0;                  
    virtual FileSystemItem* cd(const string& name) = 0; 
    virtual string getName() = 0;
    virtual bool isFolder() = 0;
};

// Leaf: File
class File : public FileSystemItem {
    string name;
    int size;
public:
    File(const string& n, int s) {
        name = n;
        size = s;
    }

    void ls(int indent = 0) override {
        cout << string(indent, ' ') << name << "\n";
    }

    void openAll(int indent = 0) override {
        cout << string(indent, ' ') << name << "\n";
    }

    int getSize() override {
        return size;
    }

    FileSystemItem* cd(const string&) override {
        return nullptr;
    }

    string getName() override {
        return name;
    }

    bool isFolder() override {
        return false;
    }
};

class Folder : public FileSystemItem {
    string name;
    vector<FileSystemItem*> children;
public:
    Folder(const string& n) {
        name = n;
    }
    ~Folder() {
        for (auto c : children) delete c;
    }

    void add(FileSystemItem* item) {
        children.push_back(item);
    }

    void ls(int indent = 0) override {
        for (auto child : children) {
            if (child->isFolder()) {
                cout <<string(indent, ' ') << "+ " << child->getName() << "\n";
            } else {
                cout <<string(indent, ' ') <<child->getName() << "\n";
            }
        }
    }

    void openAll(int indent = 0) override {
        cout << string(indent, ' ') << "+ " << name << "\n";
        for (auto child : children) {
            child->openAll(indent + 4);
        }
    }

    int getSize() override {
        int total = 0;
        for (auto child : children) {
            total += child->getSize();
        }
        return total;
    }

    FileSystemItem* cd(const string& target) override {
        for (auto child : children) {
            if (child->isFolder() && child->getName() == target) {
                return child;
            }
        }
        // not found or not a folder
        return nullptr;
    }

    string getName() override {
        return name;
    }
    bool isFolder() override {
        return true;
    }
};

int main() {
    // Build file system
    Folder* root = new Folder("root");
    root->add(new File("file1.txt", 1));
    root->add(new File("file2.txt", 1));

    Folder* docs = new Folder("docs");
    docs->add(new File("resume.pdf", 1));
    docs->add(new File("notes.txt", 1));
    root->add(docs);

    Folder* images = new Folder("images");
    images->add(new File("photo.jpg", 1));
    root->add(images);

    root->ls();

    docs->ls();

    root->openAll();

    FileSystemItem* cwd = root->cd("docs");
    if (cwd != nullptr) {
        cwd->ls();
    } else {
        cout << "\n Could not cd into docs \n";
    }

     cout << root->getSize();

    // Cleanup
    delete root;
    return 0;
}

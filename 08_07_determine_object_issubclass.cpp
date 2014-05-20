#include <iostream>

using namespace std;

class Shape {
public:
    Shape() {
        cout << "Constructing Shape" << endl;
    };
    virtual void draw() {                       // downwards (exlude myself)
        cout << "Shape draw..." << endl;
    };
    virtual ~Shape() {                          // from bottom to top (include myself)
        cout << "Shape destruction" << endl;
    }
};

class Rectangle : public Shape {
public:
    Rectangle() {
        cout << "Construcing Rectangle" << endl;
    };
    void draw() {
        cout << "Rectangle draw..." << endl;
    }
    ~Rectangle() {
        cout << "Rectangle destruction" << endl;
    }
};

class Square :  public Rectangle {
public:
    Square() {
        cout << "Constructing Square" << endl;
    };
    void draw() {
        cout << "Square draw..." << endl;
    }
    ~Square() {
        cout << "Square destruction" << endl;
    }
};

void main_0807() {
    Shape* s = new Rectangle();
    s->draw();
    
    delete s;   // Rectangle destruction, Shape destruction
    
    s = new Square();
    s->draw();  // Square draw..., no need Rectangle has virtual for draw()
    
    delete s;
    
//    if (dynamic_cast<Shape*>(&s))
//        cout << "isSubclass" << endl;
}
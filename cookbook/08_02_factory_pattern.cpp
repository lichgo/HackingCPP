#include <iostream>

class Session {};

class SessionFactory {
public:
    Session Create();
    Session* CreatePtr();
    void Create(Session*& p);
};

Session SessionFactory::Create() {
    Session s;
    return s;
}

Session* SessionFactory::CreatePtr() {
    return (new Session());
}

void SessionFactory::Create(Session*& p) {
    p = new Session();
}

// The single factory
static SessionFactory sf;

void main_0802() {
    Session* p1;
    Session* p2 = new Session();
    
    *p2 = sf.Create();
    p1 = sf.CreatePtr();
    sf.Create(p1);
}
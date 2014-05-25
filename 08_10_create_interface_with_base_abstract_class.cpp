#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class AbstractConfigFile {
public:
	// Only virtual will invoke subclass's deconstructor
	virtual ~AbstractConfigFile() {
		cout << "DesAbstractConfigFile..." << endl;
	}

	virtual void getKey(const string& header, const string& key, string& val) const = 0;

	virtual void exists(const string& header, const string& key, string& val) const = 0;

	virtual void test() const {
		cout << "AbstractConfigFile test..." << endl;
	}
};

class TXTConfigFile : public AbstractConfigFile {
public:
	TXTConfigFile() {}
	TXTConfigFile(istream& in) : in_(&in) {}
	~TXTConfigFile() {
		cout << "Destructing TXTConfigFile..." << endl;
	}

	virtual void getKey(const string& header, const string& key, string& val) const {};
	virtual void exists(const string& header, const string& key, string& val) const {};

	void test() {
		cout << "TXTConfigFile test..." << endl;
	}
protected:
	istream* in_;
};

class MyConfigFile {
public:
	
	MyConfigFile() {}

	~MyConfigFile() {
		cout << "Desconstructing MyConfigFile..." << endl;
	}

	void setConfigFile(const AbstractConfigFile* p) {
		config_ = p;
		cout << "Set config_ done..." << endl;
	}

	void myMethod();

private:
	const AbstractConfigFile* config_;	// point to a const ACF instance
	// AbstractConfigFile* const cc_;	// need to be initiazlied in the init list
	// const int val;					// same as above
};

void MyConfigFile::myMethod() {
	cout << "myMethod..." << endl;
	config_->getKey(string(""), string(""), string(""));
	config_->test();
}


// Writing a pure interface
class Person {
public:
	virtual void eat() = 0;
	virtual void sleep() = 0;
	virtual void walk() = 0;
	virtual void jump() = 0;
	virtual void setFirstname(const string& s) { firstname_ = s;  }
	virtual void setLastname(const string& s) { lastname_ = s;  }
protected:
	string firstname_;
	string lastname_;
};

class IAirborne {
public:
	virtual void fly() = 0;
	virtual void up() = 0;
	virtual void down() = 0;
};

class Superman : public Person,
	public IAirborne {
public:
	virtual void eat();
	virtual void sleep();
	virtual void walk();
	virtual void jump();
	virtual void fly();
	virtual void up();
	virtual void down();
	void setFirstname(const string& s) {
		Person::setFirstname(s);
	}
};

void main_0810() {
	ifstream in("Readme.md");
	TXTConfigFile txtcfg(in);
	AbstractConfigFile* acf = new TXTConfigFile(in);
	acf->test();
	// acf will be resease automatically bacause it points to a heap space
	delete acf;

	MyConfigFile m;
	m.setConfigFile(&txtcfg);	// p = &txtcfg; config_ = p;

	m.myMethod();

	const int* ip;
	ip = new int(3);	// ptr to (const type) can refer to (type)
}
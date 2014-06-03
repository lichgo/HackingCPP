class ObjectManager {
public:
	template<typename T>
	T* gimmeAnObject();

	template<typename T>
	void gimmeAnObject(T*& p);
};

template<typename T>
T* ObjectManager::gimmeAnObject() {
	return (new T);
}

template<typename T>
void ObjectManager::gimmeAnObject(T*& p) {
	p = new T;
}

class X {};
class Y {};

void main_0812() {
	ObjectManager om;

	X* p1 = om.gimmeAnObject<X>();	// specific the type when invoking the template function
	Y* p2 = om.gimmeAnObject<Y>();

	om.gimmeAnObject(p1);	// no need ot specific, compiler can deduce T from the arguments
	om.gimmeAnObject(p2);	
}
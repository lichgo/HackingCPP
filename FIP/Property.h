#ifndef FINMATH_PROPERTY_H_

#define FINMATH_PROPERTY_H_

#include <string>

using namespace std;

namespace FinMath {

template<class Name = string, class Type = double>
class Property {
private:
	Name _name;
	Type _type;
public:
	Property();
	Property(const Name& n, const Type& t);
	Property(const Name& n);
	Property(const Property<Name, Type>& source);

	virtual ~Property();

	virtual Name name() const;
	virtual void name(const Name& n);

	virtual Type operator()() const;
	virtual void operator()(const Type& t);

	bool operator==(const Property<Name, Type>& source);
};

}

#endif
#ifndef FINMATH_SIMPLEPROPERTYSET_H_

#define FINAMTH_SIMPLEPROPERTYSET_H_

#include "Property.h"
#include <list>
#include <set>

namespace FinMath {

template<class N, class V>
class SimplePropertySet {
private:
	N _name;
	list<Property<N, V>> _list;
public:
	typedef typename list<Property<N, V>>::iterator iterator;
	typedef typename list<Property<N, V>>::const_iterator const_iterator;

	SimplePropertySet();
	SimplePropertySet(const N& name);
	SimplePropertySet(const SimplePropertySet<N, V>& source);
	
	virtual ~SimplePropertySet();

	iterator Begin();
	const_iterator Begin() const;
	iterator End();
	const_iterator End() const;

	int Count() const;
	N operator()() const;
	bool hasProperty(const N& searchedName) const;
	void operator()(const N& name) const;

	void add(const Property<N, V>& p);
	void add(const SimplePropertySet<N, V>& p);
	void remove(const N& value);

	SimplePropertySet<N, V>& operator = (const SimplePropertySet<N, V>& source);
};

}

#endif
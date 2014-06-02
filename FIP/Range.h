#ifndef FINMATH_RANGE_H_

#define FINMATH_RANGE_H_

namespace FinMath {

template<class T>
class Range {
private:
	T _low;
	T _high;
public:
	// Constructors
	Range();
	Range(const T& l, const T& h);
	Range(const Range<T>& another);

	// Destructors
	virtual ~Range();

	// Modifier functions
	void low(const T& l);
	void high(const T& h);

	// Accessing functions
	T low() const;
	T high() const;

	T spread() const;

	// Boolean functions
	bool left(const T& val) const;
	bool right(const T& val) const;
	bool contains(const T& val) const;

	// Operator overloading
	Range<T>& operator=(const Range<T>& another);
};

template<class T>
Range<T>::Range() {};

template<class T>
Range<T>::Range(const T& l, const T& h) : _low(l), _high(h) {}

template<class T>
Range<T>::Range(const Range<T>& another) : _low(another._low), _high(another._high) {}

template<class T>
Range<T>::~Range() {}

template<class T>
T Range<T>::spread() const {
	return _high - _low;
}

template<class T>
bool Range<T>::contains(const T& val) const {
	return (val <= _high && val >= _low);
}

}

#endif
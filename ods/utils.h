#ifndef UTILS_H_

#define UTILS_H_

namespace ods {

template<class T> inline
T min(const T& a, const T& b) {
	return a < b ? a : b;
}

template<class T> inline
T max(const T& a, const T& b) {
	return a < b ? b : a;
}

template<class T> inline
int compare(const T& a, const T& b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

template<class T> inline
int equals(const T& a, const T& b) {
	return a == b;
}

inline
unsigned intVal(int x) {
	return (unsigned)x;
}

}

#endif
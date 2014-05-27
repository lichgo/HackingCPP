#if !defined hash_table_h

#define hash_table_h

#include <assert.h>
#include "../LinkedList/list.h"

const int sizeTable = 127;

class HashTable {
public:
	HashTable() {}
	~HashTable() {}
	void add(const char* str, int id);
	const List& find(const char* str) const;
private:
	int _hash(char const* str) const;
	List _list[sizeTable];		// sizeTable linked lists
};

void HashTable::add(const char* str, int id) {
	int h = _hash(str);
	_list[h].add(id);
}

const List& HashTable::find(const char* str) const {
	return _list[_hash(str)];
}

int HashTable::_hash(const char* str) const {
	assert(str != 0 && str[0] != 0);
	unsigned h = str[0];
	for (int i = 1; str[i] != 0; ++i) {
		h = (h << 4) + str[i];
	}
	return h % sizeTable;
}

#endif
#include "Set.h"
#include "SetITerator.h"
#include <iostream>
#include <exception>
#include <math.h>
using namespace std;

//function that gives the hashCode of an element (absolute value -> only positive positions)
int hashCode(TElem e) {
	return abs(e);
}


int Set::h(TElem e, int i) const
{
	//BC:Tita(1)  WC:Tita(1)  Overall:O(n)
	return (hashCode(e) % m + i * (1 + hashCode(e) % (m - 1))) % m;
}

Set::Set() {
	//BC:Tita(m)  WC:Tita(m)  Overall:O(m)
	n = 0;
	m = MAX;
	for (int i = 0; i < m; i++) {
		e[i] = NULL_TELEM;
	}
}


bool Set::add(TElem elem) {
	//BC:Tita(1)  WC:Tita(n)  AVARAGE:Tita(1)  Overall:O(n)
	if (search(elem))
		return false;
	else {
		int i = 0;
		int pos = h(elem, i);
		while (i < m && e[pos] != NULL_TELEM && e[pos] != DELETED)
		{
			i++;
			pos = h(elem, i);
		}
		if (i == m) {
			//resize & rehash, but we assume that m is high-enough, so this is not needed
		}
		e[pos] = elem;
		n++;
		return true;

	}
}



bool Set::remove(TElem elem) {
	//BC:Tita(1)  WC:Tita(n) Overall:O(n)
	int i = 0;
	int pos = h(elem, i);
	bool found = false;
	while (i < m && e[pos] != NULL_TELEM && !found)
		if (e[pos] == elem) {
			found = true;
			e[pos] = DELETED;
		}
		else {
			i++;
			pos = h(elem, i);
		}
	if (found) {
		n--;
		return true;
	}
	return false;
}

bool Set::search(TElem elem) const
{
	//BC:Tita(1)  WC:Tita(n)  AVARAGE:Tita(1)  Overall:O(n)
	int i = 0;
	int pos = h(elem, i);
	bool found = false;
	while (i < m && e[pos] != NULL_TELEM && !found) {
		if (e[pos] == elem)
			found = true;
		else {
			i++;
			pos = h(elem, i);
		}
	}
	if (found)
		return true;
	return false;
}



int Set::size() const {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	return n;

}



bool Set::isEmpty() const {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	if (this->size() != 0)
		return false;
	return true;
}

SetIterator Set::iterator() const {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	return SetIterator(*this);
}


Set::~Set() {
}



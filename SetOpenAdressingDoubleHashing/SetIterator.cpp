#include "SetIterator.h"
#include "Set.h"
#include <exception>
#include<iostream>
using namespace std;


SetIterator::SetIterator(const Set& m) : set(m)
{
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	current = 0;
	move();
}

void SetIterator::move()
{
	//BC:Tita(1)  WC:Tita(m)  Overall:O(m)
	while ((current < set.m) && (set.e[current] == NULL_TELEM || set.e[current] == DELETED))
		current++;
}
void SetIterator::first() {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	current = 0;
	move();
}


void SetIterator::next() {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	if (!valid()) {
		throw std::exception();
	}
	current++;
	move();

}


TElem SetIterator::getCurrent()
{
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	if (!valid()) {
		throw std::exception();
	}
	return set.e[current];
}

bool SetIterator::valid() const {
	//BC:Tita(1)  WC:Tita(1)  Overall:O(1)
	return (current < set.m);
}




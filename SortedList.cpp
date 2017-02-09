#include <iostream>
#include <iterator>
#include <algorithm>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

void SortedList::prepend(int value)
{
	list<int>::iterator it;
	it = data.begin();
	data.insert(it,value);
}

void SortedList::append(int value)
{
	list<int>::iterator it;
	it = data.end();
	data.insert(it,value);
}

bool SortedList::find(int value) const
{
	bool found = (std::find(data.begin(), data.end(), value) != data.end());
	return found;
}
    
int SortedList::get_value(int i) const
{
	int x = 0;
	std::list<int>::const_iterator it = std::next(data.begin(), i);
	x = *it;
	return x;
}
    
void SortedList::clear()
{
	list<int>::iterator it;
	for(it = data.begin(); it == data.end(); it++)
	{
		it = data.erase(it);
	}
}

bool SortedList::check()
{
	if (data.size() == 0) 
		return true;
	list<int>::iterator it = data.begin();
	int prev = *it;
	while ((++it != data.end()) && (prev <= *it));
		return it == data.end();
}

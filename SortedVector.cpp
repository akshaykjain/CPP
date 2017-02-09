#include <iostream>
#include <iterator>
#include <algorithm>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

void SortedVector::prepend(int value)
{
	vector<int>::iterator it;
	it = data.begin();
	data.insert(it,value);
}

void SortedVector::append(int value)
{
	vector<int>::iterator it;
	it = data.end();
	data.insert(it,value);
}

bool SortedVector::find(int value) const
{
	bool found = (std::find(data.begin(), data.end(), value) != data.end());
	return found;
}

int SortedVector::get_value(int i) const
{
	int x = 0;
	std::vector<int>::const_iterator it = std::next(data.begin(), i);
	x = *it;
	return x;
}

void SortedVector::clear()
{
	vector<int>::iterator it;
	for(it = data.begin(); it == data.end(); it++)
	{
		it = data.erase(it);
	}
}

bool SortedVector::check()
{
    if (data.size() == 0) 
		return true;
	vector<int>::iterator it = data.begin();
	int prev = *it;
	while ((++it != data.end()) && (prev <= *it));
		return it == data.end();
}

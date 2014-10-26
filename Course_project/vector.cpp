#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"

using namespace std;

template <class TEntry> vector<TEntry> :: vector()
{
	reserve = 10;
	size = 0;
	beginPtr = new TEntry[reserve];
}

template <class TEntry> vector<TEntry> :: vector(int newSize)
{
	size = newSize;
	reserve = max(size, reserve);
	beginPtr = new Tentry[reserve];
}

template <class TEntry> vector<TEntry> :: ~vector()
{
	delete [] beginPtr;
}

template <class TEntry> void vector<TEntry> :: pushback(const TEntry &toAdd)
{
	if(size == reserve)
	{
		TEntry *temp = beginPtr;
		reserve *= 2;
		beginPtr = new TEntry[reserve];
		if(temp)
			memcpy(beginPtr, temp, sizeof(TEntry)*size);
		beginPtr[size + 1] = toAdd;
		size++;
		if(temp)
		delete [] temp;
	}
	else
	{
		beginPtr[size + 1] = toAdd;
		size++;
	}
}

template <class TEntry> TEntry* vector<TEntry> :: begin()
{
	return beginPtr;
}

template <class TEntry> int vector<TEntry> :: getSize()
{
	return size;
}

template <class TEntry> TEntry* vector<TEntry> :: end()
{
	return beginPtr + size;
}

template <class TEntry> TEntry& vector<TEntry> :: operator[](int index)
{
	if(index < 0 || index >= size)
		throw IndexOutOfRange;
	return beginPtr[index];
}

template <class TEntry> TEntry& vector<TEntry> :: operator=(TEntry newBeginPtr)
{
	delete [] beginPtr;
	size = newBeginPtr.getSize();
	beginPtr = new TEntry[newSize];
	for(int i = 0; i < size; i++)
		beginPtr[i] = newBeginPtr[i];
	return *beginPtr;
}

template <class TEntry> int vector<TEntry> :: reserve()
{
	return reserve;
}
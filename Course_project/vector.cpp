#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"

using namespace std;

template <class TEntry> vector<TEntry> :: vector()
{
	size = 0;
	beginPtr = NULL;
}

template <class TEntry> vector<TEntry> :: vector(int newSize)
{
	size = newSize;
	beginPtr = new Tentry[size];
}

template <class TEntry> vector<TEntry> :: ~vector()
{
	delete [] beginPtr;
}

template <class TEntry> void vector<TEntry> :: pushback(const TEntry &toAdd)
{
	TEntry *temp = beginPtr;
	beginPtr = new TEntry[size + 1];
	if(temp)
		memcpy(beginPtr, temp, sizeof(TEntry)*size);
	ms[size + 1] = toAdd;
	size++;
	if(temp)
		delete [] temp;
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
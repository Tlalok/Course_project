#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))
class IndexOutOfRange{};

template <class TEntry> vector<TEntry> :: vector()
{
	_reserve = 10;
	_size = 0;
	beginPtr = new TEntry[_reserve];
}

template <class TEntry> vector<TEntry> :: vector(uint newSize)
{
    _reserve = 10;
	_size = newSize;
	//reserve_ = max(_size, _reserve);
    _reserve = max(_size, _reserve);
	beginPtr = new Tentry[_reserve];
}
template <class TEntry> vector<TEntry> :: ~vector()
{
	delete [] beginPtr;
}

template <class TEntry> void vector<TEntry> :: push_back(TEntry &toAdd)
{
	if(_size == _reserve)
	{
		TEntry *temp = beginPtr;
		_reserve *= 2;
		beginPtr = new TEntry[_reserve];
		if(temp)
			memcpy(beginPtr, temp, sizeof(TEntry) * _size);
		beginPtr[_size] = toAdd;
		_size++;
		if(temp)
			delete [] temp;
	}
	else
	{
		beginPtr[_size] = toAdd;
		_size++;
	}
}

template <class TEntry> TEntry* vector<TEntry> :: begin()
{
	return beginPtr;
}

template <class TEntry> uint vector<TEntry> :: size()
{
	return _size;
}

template <class TEntry> TEntry* vector<TEntry> :: end()
{
	return beginPtr + _size;
}

template <class TEntry> TEntry& vector<TEntry> :: operator[](uint index)
{
	if(index < 0 || index >= _size)
		throw IndexOutOfRange();
	return beginPtr[index];
}

template <class TEntry> vector<TEntry>& vector<TEntry> :: operator=(vector<TEntry>& toCopy)
{
	delete [] beginPtr;
	_size = toCopy.size();
	beginPtr = new TEntry[_size];
	for(uint i = 0; i < _size; i++)
		beginPtr[i] = toCopy[i];
	return *this;
}

template <class TEntry> uint vector<TEntry> :: reserve()
{
	return _reserve;
}

template <class TEntry> bool vector<TEntry> :: isEmpty()
{
	return _size == 0;
}
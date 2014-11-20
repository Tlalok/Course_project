#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))
class IndexOutOfRange{};
class BeginPtrisNULL{};

template <class TEntry> Vector<TEntry> :: Vector()
{
	_reserve = 10;
	_size = 0;
	beginPtr = new TEntry[_reserve];
}

template <class TEntry> Vector<TEntry> :: Vector(uint newSize)
{
    _reserve = 10;
	_size = 0;
    _reserve = max(newSize, _reserve);
	beginPtr = new Tentry[_reserve];
}

template <class TEntry>
Vector<TEntry> :: Vector(const Vector<TEntry> &toCopy)
{
    _size = toCopy._size;
    _reserve = toCopy._reserve;
    beginPtr = new TEntry[_reserve];
	for(uint i = 0; i < _size; i++)
        beginPtr[i] = toCopy.beginPtr[i];
}

template <class TEntry> Vector<TEntry> :: ~Vector()
{
	delete [] beginPtr;
}

template <class TEntry> void Vector<TEntry> :: push_back(TEntry &toAdd)
{
	if(_size == _reserve)
	{
		TEntry *temp = beginPtr;
		_reserve *= 2;
		beginPtr = new TEntry[_reserve];
		if(temp)
            for (uint i = 0; i < _size; i++)
                beginPtr[i] = temp[i];
        else
            throw BeginPtrisNULL();
		beginPtr[_size] = toAdd;
		_size++;
	    delete [] temp;
	}
	else
	{
		beginPtr[_size] = toAdd;
		_size++;
	}
}

template <class TEntry> TEntry* Vector<TEntry> :: begin()
{
	return beginPtr;
}

template <class TEntry> uint Vector<TEntry> :: size()
{
	return _size;
}

template <class TEntry> TEntry* Vector<TEntry> :: end()
{
	return beginPtr + _size;
}

template <class TEntry> TEntry& Vector<TEntry> :: operator[](uint index)
{
	if(index < 0 || index >= _size)
		throw IndexOutOfRange();
	return beginPtr[index];
}

template <class TEntry> Vector<TEntry>& Vector<TEntry> :: operator=(Vector<TEntry>& toCopy)
{
    if (this == &toCopy)
        return *this;
	delete [] beginPtr;
	_size = toCopy.size();
    _reserve = toCopy.reserve();
    beginPtr = new TEntry[_reserve];
	for(uint i = 0; i < _size; i++)
		beginPtr[i] = toCopy[i];
	return *this;
}

template <class TEntry> uint Vector<TEntry> :: reserve()
{
	return _reserve;
}

template <class TEntry> bool Vector<TEntry> :: empty()
{
	return _size == 0;
}
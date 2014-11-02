#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#define max(a, b) (((a) > (b)) ? (a) : (b))
class IndexOutOfRange{};

template <class TEntry> Vector<TEntry> :: Vector()
{
	_reserve = 10;
	_size = 0;
	beginPtr = new TEntry[_reserve];
}

template <class TEntry> Vector<TEntry> :: Vector(uint newSize)
{
	_size = newSize;
	reserve_ = max(_size, _reserve);
	beginPtr = new Tentry[_reserve];
}
template <class TEntry> Vector<TEntry> :: ~Vector()
{
	delete [] beginPtr;
}

template <class TEntry> void Vector<TEntry> :: push_back(const TEntry &toAdd)
{
	if(_size == _reserve)
	{
		TEntry *temp = beginPtr;
		_reserve *= 2;
		beginPtr = new TEntry[_reserve];
		if(temp)
			memcpy(beginPtr, temp, sizeof(TEntry)*_size);
		beginPtr[_size + 1] = toAdd;
		_size++;
		if(temp)
			delete [] temp;
	}
	else
	{
		beginPtr[_size + 1] = toAdd;
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

template <class TEntry> TEntry& Vector<TEntry> :: operator=(TEntry newBeginPtr)
{
	delete [] beginPtr;
	_size = newBeginPtr.getSize();
	beginPtr = new TEntry[newSize];
	for(uint i = 0; i < _size; i++)
		beginPtr[i] = newBeginPtr[i];
	return *beginPtr;
}

template <class TEntry> uint Vector<TEntry> :: reserve()
{
	return _reserve;
}

template <class TEntry> bool Vector<TEntry> :: isEmpty()
{
	return _size == 0;
}
#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef unsigned uint;

template <class TEntry> 
class Vector
{
	TEntry *beginPtr;
	uint _size;
	uint _reserve;
public:
	Vector();
	Vector(uint reserve);
    Vector(const Vector<TEntry> &toCopy);
	~Vector();
	void push_back(TEntry & toAdd);
	TEntry* begin();
	TEntry* end();
	uint size();
	TEntry &operator[](uint index);
	Vector<TEntry> &operator=(Vector<TEntry>& toCopy);
	uint reserve();
	bool empty();
	Vector<TEntry>& del(<TEntry> toDelete);
};
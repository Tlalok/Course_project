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
	Vector(uint);
	~Vector();
	void push_back(TEntry &);
	TEntry* begin();
	TEntry* end();
	uint size();
	TEntry &operator[](uint);
	Vector<TEntry> &operator=(Vector<TEntry>&);
	uint reserve();
	bool empty();
};
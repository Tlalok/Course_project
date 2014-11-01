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
	void push_back(const TEntry &);
	TEntry* begin();
	TEntry* end();
	uint size();
	TEntry &operator[](uint);
	TEntry &operator=(TEntry);
	uint reserve();
	bool isEmpty();
};
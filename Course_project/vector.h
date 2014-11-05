#define _CRT_SECURE_NO_WARNINGS

typedef unsigned uint;

template <class TEntry> 
class vector
{
	TEntry *beginPtr;
	uint _size;
	uint _reserve;
public:
	vector();
	vector(uint);
	~vector();
	void push_back(TEntry &);
	TEntry* begin();
	TEntry* end();
	uint size();
	TEntry &operator[](uint);
	vector<TEntry> &operator=(vector<TEntry>&);
	uint reserve();
	bool isEmpty();
};
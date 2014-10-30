#define _CRT_SECURE_NO_WARNINGS

template <class TEntry> 
class _vector
{
	TEntry *beginPtr;
	int _size;
	int _reserve;
public:
	_vector();
	_vector(int);
	~_vector();
	void push_back(const TEntry &);
	TEntry* begin();
	TEntry* end();
	int size();
	TEntry &operator[](int);
	TEntry &operator=(TEntry);
	int reserve();
};
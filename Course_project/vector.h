#define _CRT_SECURE_NO_WARNINGS

using namespace std;

template <class TEntry> class vector
{
	TEntry *beginPtr;
	int size;
	int reserve_;
public:
	vector();
	vector(int);
	~vector();
	void pushback(const TEntry &);
	TEntry* begin();
	TEntry* end();
	int getSize();
	TEntry &operator[](int);
	TEntry &operator=(TEntry);
	int reserve();
};
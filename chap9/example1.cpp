#include <cstdlib>
#include <memory>
#include <iostream>

struct myclass
{
	int data1;
	int data2;
};

template<typename T>
class myallocator
{
public:
	using value_type = T;
	using pointer = T *;
	using size_type = std::size_t;
public:
	myallocator() = default;

	template<typename U>
	myallocator(const myallocator<U> &other) noexcept
	{ (void) other; }

	pointer allocate(size_type n)
	{
		if (auto ptr = static_cast<pointer>(malloc(sizeof(T) * n)))
		{
			return ptr;
		}
		throw std::bad_alloc();
	}

	void deallocate(pointer p, size_type n)
	{ (void) n; return free(p); }
};

template <typename T1, typename T2>
bool operator==(const myallocator<T1> &, const myallocator<T2> &)
{ return true; }

template <typename T1, typename T2>
bool operator!=(const myallocator<T1> &, const myallocator<T2> &)
{ return false; }

int main(int argc, char **argv)
{
	myallocator<myclass> myalloc;

	myclass *ptr = myalloc.allocate(1);
	const myclass *cptr = myalloc.allocate(1);


	std::cout << (*ptr).data1 << '\n';
	std::cout << (*cptr).data2 << '\n';

	std::cout << ptr->data1 << '\n';
	std::cout << cptr->data2 << '\n';

	myallocator<myclass> myalloc1;
	myallocator<myclass> myalloc2;

	std::cout << std::boolalpha;
	
	std::cout << (myalloc1 == myalloc2) << '\n';
	std::cout << (myalloc1 != myalloc2) << '\n';
}

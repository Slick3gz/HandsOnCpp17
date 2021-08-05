#include <iostream>
#include <memory>
#include <list>
//#include <vector>
//#include <deque>

template<typename T>
class myallocator
{
public:
	using value_type = T;
	using pointer = T *;
	using size_type = std::size_t;
	using is_always_equal = std::true_type;

public:

	myallocator()
	{
		std::cout << this << " constructor, sizeof(value_type): "
			<< sizeof(value_type) << '\n';
	}

	template <typename U>
	myallocator(const myallocator<U> &other) noexcept
	{ (void) other; }
	
	myallocator(const myallocator &other) noexcept
	{
		(void) other;
		std::cout << this << " copy constructor, sizeof(value_type): "
			<< sizeof(value_type) << '\n';
	}


	myallocator(myallocator &&other) noexcept
	{
		(void) other;
		std::cout << this << " move constructor, sizeof(value_type): "
			<< sizeof(value_type) << '\n';

	}

	myallocator &operator=(myallocator &&other) noexcept
	{
		(void) other;
		std::cout << this << " move assignment, sizeof(value_type): "
			<< sizeof(value_type) << '\n';

		return *this;
	}

	myallocator &operator=(const myallocator &other) noexcept
	{
		(void) other;
		std::cout << this << " copy assignment, sizeof(value_type): "
			<< sizeof(value_type) << '\n';

		return *this;
	}

	pointer allocate(size_type n)
	{
		if (auto ptr = static_cast<pointer>(malloc(sizeof(value_type) * n)))
		{
			std::cout << this << " A [" << n << "]: "
				<< ptr << '\n';
			return ptr;
		}
		throw std::bad_alloc();
	}

	void deallocate(pointer p, size_type n)
	{
		(void) n;

		std::cout << this << " D [" << n << "]: " << p << '\n';
		free(p);
	}

};

template <typename T1, typename T2>
bool operator==(const myallocator<T1> &, const myallocator<T2> &)
{ return true; }

template <typename T1, typename T2>
bool operator!=(const myallocator<T1> &, const myallocator<T2> &)
{ return false; }

int main(int argc, char **argv)
{
	/*
	std::list<int, myallocator<int>> mylist;
	mylist.emplace_back(42);
	*/

	/*
	std::vector<int, myallocator<int>> myvector;
	myvector.emplace_back(42);
	myvector.emplace_back(42);
	myvector.emplace_back(42);
	*/

	/*
	std::deque<int, myallocator<int>> mydeque;
	for (auto i = 0; i < 127; i++)
		mydeque.emplace_back(42);
	for (auto i = 0; i < 127; i++)
		mydeque.emplace_back(42);
	for (auto i = 0; i < 127; i++)
		mydeque.emplace_back(42);
	*/

	std::list<int, myallocator<int>> mylist1;
	std::list<int, myallocator<int>> mylist2;
	
	mylist1.emplace_back(42);
	mylist1.emplace_back(42);

	std::cout << "---------------------------------------\n";
	//mylist2 = mylist1;
	mylist2 = std::move(mylist1);
	std::cout << "---------------------------------------\n";

	
	mylist2.emplace_back(42);
	mylist2.emplace_back(42);


	return EXIT_SUCCESS;
}

#include <iostream>
#include <memory>
#include <list>

class myallocator_object
{
public:
	using size_type = std::size_t;

public:

	void *allocate(size_type size)
	{
		if (auto ptr = malloc(size))
		{
			std::cout << this << " A " << ptr << '\n';
			return ptr;
		}

		throw std::bad_alloc();
	}

	void deallocate(void *ptr)
	{
		std::cout << this << " D " << ptr << '\n';
		free(ptr);
	}
};

template <typename T>
class myallocator
{
private:
	std::shared_ptr<myallocator_object>  m_object;

	template <typename T1, typename T2>
	friend bool operator==(const myallocator<T1> &lhs, const myallocator<T2>
			&rhs);

	
	template <typename T1, typename T2>
	friend bool operator!=(const myallocator<T1> &lhs, const myallocator<T2>
			&rhs);

	template <typename U>
	friend class myallocator;

public:
	using value_type = T;
	using pointer = T *;
	using size_type = std::size_t;
	using is_always_equal = std::false_type;

public:
	myallocator() :
		m_object{std::make_shared<myallocator_object>()}
	{
		std::cout << this << " constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}

	myallocator(myallocator &&other) noexcept:
		m_object{std::move(other.m_object)}
	{
		std::cout << this << " move constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}

	myallocator(const myallocator &other) noexcept:
		m_object{other.m_object}
	{
		std::cout << this << " copy constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}


	myallocator &operator=(myallocator &&other) noexcept
	{
		std::cout << this << " move assignement, sizeof(T): "
			<< sizeof(T) << '\n';
		m_object = std::move(other.m_object);
		return *this;
	}

	myallocator &operator=(const myallocator &&other) noexcept
	{
		std::cout << this << " copy assignement, sizeof(T): "
			<< sizeof(T) << '\n';
		m_object = other.m_object;
		return *this;
	}

	template <typename U>
	myallocator(const myallocator<U> &other) noexcept 
	{
		m_object = other.m_object;
		std::cout << this << " copyc constructor (U), sizeof(T): "
			<< sizeof(T) << '\n';
	}

	pointer allocate(size_type n)
	{
		auto ptr = m_object->allocate(sizeof(T) * n);
		return static_cast<pointer>(ptr);
	}

	void deallocate(pointer p, size_type n)
	{
		(void) n;
		return m_object->deallocate(p);
	}

};

template <typename T1, typename T2>
bool operator==(const myallocator<T1> &lhs, const myallocator<T2>
			&rhs)
{
	return lhs.m_object.get() == rhs.m_object.get();
}
	
template <typename T1, typename T2>
bool operator!=(const myallocator<T1> &lhs, const myallocator<T2>
			&rhs)
{
	return lhs.m_object.get() != rhs.m_object.get();
}
	
int main(int argc, char **argv)
{
	//std::list<int, myallocator<int>> mylist;
	//mylist.emplace_back(42);

	std::list<int, myallocator<int>> mylist1;
	std::list<int, myallocator<int>> mylist2;
	
	mylist1.emplace_back(42);
	mylist1.emplace_back(42);
	
	mylist2.emplace_back(42);
	mylist2.emplace_back(42);

	std::cout << "---------------------------------------\n";
	mylist2 = std::move(mylist1);
	std::cout << "---------------------------------------\n";

	
	mylist2.emplace_back(42);
	mylist2.emplace_back(42);


}	

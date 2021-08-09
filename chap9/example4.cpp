#include <iostream>
#include <memory>
#include <stack>
#include <list>
#include <chrono>
#include <gsl/gsl-lite.hpp>


class pool
{
public:

	using size_type = std::size_t;

public:

	explicit pool(size_type size) :
		m_size{size}
	{};

	void *allocate()
	{
		if (m_addrs.empty())
		{
			this->add_addrs();
		}

		auto ptr = m_addrs.top();
		m_addrs.pop();

		return ptr;
	}

	void deallocate(void *ptr)
	{
		m_addrs.push(ptr);
	}

	void rebind(size_type size)
	{
		if (!m_addrs.empty() || !m_blocks.empty())
		{
			std::cerr << "rebind after alloc unsupported\n";
			abort();
		}

		m_size = size;
	}

private:
	void add_addrs()
	{
		constexpr const auto block_size = 0x1000;
		auto block = std::make_unique<uint8_t[]>(block_size);

		auto v = gsl::span<uint8_t>(
			block.get(), block_size
			);

		auto total_size =
			v.size() % m_size == 0 ? v.size() : v.size() - m_size;

		for (auto i = 0; i < total_size; i+= m_size)
		{
			m_addrs.push(&v[i]);
		}

		m_blocks.push(std::move(block));
	}

private:
	size_type m_size;

	std::stack<void *> m_addrs{};
	std::stack<std::unique_ptr<uint8_t[]>> m_blocks{};
};


template<typename T>
class myallocator
{
public:
	using value_type = T;
	using pointer = T *;
	using size_type = std::size_t;
	using is_always_equal = std::false_type;
	using propagate_on_container_copy_assignment = std::false_type;
	using propagate_on_container_move_assignment = std::true_type;
	using propagate_on_container_swap = std::true_type;
	
public:
	myallocator() :
		m_pool{std::make_shared<pool>(sizeof(T))}
	{
		std::cout << this << " constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}

	template<typename U>
	myallocator(const myallocator<U> &other) noexcept:
		m_pool{other.m_pool}
	{
		std::cout << this << " copy constructor (U), sizeof(T): "
			<< sizeof(T) << '\n';
		m_pool->rebind(sizeof(T));
	}

	myallocator(myallocator &&other) noexcept:
		m_pool{std::move(other.m_pool)}
	{
		std::cout << this << " move constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}

	myallocator &operator=(myallocator &&other) noexcept
	{
		std::cout << this << " move assignment, sizeof(T): "
			<< sizeof(T) << '\n';

		m_pool = std::move(other.m_pool);
		return *this;
	}

	myallocator(const myallocator &other) noexcept :
		m_pool{other.m_pool}
	{
		std::cout << this << " copy constructor, sizeof(T): "
			<< sizeof(T) << '\n';
	}

	myallocator &operator=(const myallocator &other) &noexcept
	{
		std::cout << this << " copy assignment, sizeof(T): "
			<< sizeof(T) << '\n';

		m_pool = other.m_pool;
		return *this;
	}

	pointer allocate(size_type n)
	{
		if (n != 1)
			return static_cast<pointer>(malloc(sizeof(T) * n));
		return static_cast<pointer>(m_pool->allocate());
	}

	void deallocate(pointer ptr, size_type n)
	{
		if (n != 1)
		{
			free(ptr);
		}

		m_pool->deallocate(ptr);
	}

private:
	std::shared_ptr<pool> m_pool;

	template<typename T1, typename T2>
	friend bool operator==(const myallocator<T1> &lhs, const myallocator<T2> &rhs);

	template<typename T1, typename T2>
	friend bool operator!=(const myallocator<T1> &lhs, const myallocator<T2> &rhs);
};


template<typename T1, typename T2>
bool operator==(const myallocator<T1> &lhs, const myallocator<T2> &rhs)
{
	return lhs.m_pool.get() == rhs.m_pool.get();
}

template<typename T1, typename T2>
bool operator!=(const myallocator<T1> &lhs, const myallocator<T2> &rhs)
{
	return lhs.m_pool.get() != rhs.m_pool.get();
}

template<typename FUNC>
auto benchmark(FUNC func)
{
	auto stime = std::chrono::high_resolution_clock::now();
	func();
	auto etime = std::chrono::high_resolution_clock::now();

	return (etime - stime).count();
}

int main(int argc, char **argv)
{
	constexpr const auto num = 100000;

	std::list<int> mylist1;

	std::list<int, myallocator<int>> mylist2;

	auto time1 = benchmark([&]
	{
		for (auto i = 0; i < num; i++)
		{
			mylist1.emplace_back(42);
		}
	});

	auto time2 = benchmark([&]
	{
		for (auto i = 0; i < num; i++)
		{
			mylist2.emplace_back(42);
		}
	});

	std::cout << "[TEST] add many:\n";
	std::cout << " - time1: " << time1 << '\n';
	std::cout << " - time2: " << time2 << '\n';

	return EXIT_SUCCESS;
}

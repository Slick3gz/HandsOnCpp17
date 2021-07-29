/*--------------------------------------------------------------------------*/
#define SNIPPET_60
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--------------------------- Headers & Functions --------------------------*/
/*--------------------------------------------------------------------------*/

/****************************************************************************/
/************************* Basic Memory Types *******************************/
/****************************************************************************/
#ifdef SNIPPET_01
#include <iostream>

int bss_mem = 0;
int data_mem = 42;

#endif

#ifdef SNIPPET_02
#include <iostream>
#endif


#ifdef SNIPPET_03
#include <iostream>
#endif

#ifdef SNIPPET_04
#include <iostream>
#endif


#ifdef SNIPPET_05
#include <iostream>
#endif

#ifdef SNIPPET_06
#include <iostream>

class myclass
{

public:
	~myclass()
	{
		std::cout << "my delete\n";
	}
};
#endif
/****************************************************************************/

/****************************************************************************/
/*************************** Aligning Memory ********************************/
/****************************************************************************/
#ifdef SNIPPET_07
#include <iostream>

alignas(0x1000) int ptr[42];
#endif

#ifdef SNIPPET_08
#include <iostream>
#endif

#ifdef SNIPPET_09
#include <iostream>
#endif

#ifdef SNIPPET_10
#include <iostream>
#endif

#ifdef SNIPPET_11
#include <iostream>
#endif

#ifdef SNIPPET_12
#include <iostream>

using aligned_int alignas(0x1000) = int;
#endif

#ifdef SNIPPET_13
#include <iostream>

using aligned_int alignas(0x1000) = int;
#endif

#ifdef SNIPPET_14
#include <iostream>
#endif

#ifdef SNIPPET_15
#include <iostream>
#endif

#ifdef SNIPPET_16
#include <iostream>

using aligned_int alignas(0x1000) = int;
#endif
/****************************************************************************/

/****************************************************************************/
/***************************** No Throw *************************************/
/****************************************************************************/

#ifdef SNIPPET_17
#include <iostream>

using aligned_int alignas(0x1000) = int;
#endif

#ifdef SNIPPET_18
#include <iostream>

class myclass
{
public:
	myclass()
	{
		throw std::runtime_error("The answer was not 42");
	}
};
#endif
/****************************************************************************/

/****************************************************************************/
/*************************** Placement of New *******************************/
/****************************************************************************/

#ifdef SNIPPET_19
#include <iostream>

char buf[0x1000];
#endif

#ifdef SNIPPET_20
#include <iostream>

char buf[0x1000];
#endif

#ifdef SNIPPET_21
#include <iostream>

char buf[0x1000];
#endif

#ifdef SNIPPET_22
#include <iostream>

alignas(0x1000) char buf[0x1000];
#endif

#ifdef SNIPPET_23
#include <iostream>

alignas(0x1000) char buf[0x1000];
#endif
/****************************************************************************/

/****************************************************************************/
/*********************** Overloading ****************************************/
/****************************************************************************/
#ifdef SNIPPET_24
#include <iostream>

void *
operator new (std::size_t count)
{
	// WARNING: Do not use std::cout here
	return malloc(count);
}

void
operator delete(void* ptr)
{
	// WARNING: Do not use std::cout here
	return free(ptr);
}
#endif

#ifdef SNIPPET_25
#include <iostream>

void *
operator new[](std::size_t count)
{
	// WARNING: Do not use std::cout here
	return malloc(count);
}

void
operator delete[](void* ptr)
{
	// WARNING: Do not use std::cout here
	return free(ptr);
}
#endif

#ifdef SNIPPET_26
#include <iostream>

std::size_t allocations = 0;

void *
operator new (std::size_t count)
{
	if (count >= 0x1000)
	{
		allocations++;
	}
	return malloc(count);
}

void
operator delete(void* ptr)
{
	return free(ptr);
}
#endif

#ifdef SNIPPET_27
#include <iostream>

std::size_t allocations = 0;

void *
operator new (std::size_t count)
{
	if (count >= 0x1000)
	{
		allocations++;
	}
	return malloc(count);
}

void
operator delete(void* ptr)
{
	return free(ptr);
}

struct mystruct
{
	char buf[0x1000];
};
#endif

/******************************************************************************
 * 			Class Specific Overloads
 *****************************************************************************/

#ifdef SNIPPET_28
#include <iostream>

class myclass
{
public:
	void * operator new (std::size_t count)
	{
		std::cout << "my new\n";
		return ::operator new (count);
	}

	void operator delete(void *ptr)
	{
		std::cout << "my delete\n";
		return ::operator delete (ptr);
	}
};

#endif

#ifdef SNIPPET_29
#include <iostream>

class myclass
{
public:
	void * operator new (std::size_t count, std::align_val_t al)
	{
		std::cout << "my new\n";
		return ::operator new (count, al);
	}

	void operator delete(void *ptr, std::align_val_t al)
	{
		std::cout << "my delete\n";
		return ::operator delete (ptr, al);
	}
};

using aligned_myclass alignas(0x1000) = myclass;
#endif

/******************************************************************************
 *			Smart Pointers & Ownership 			
 *****************************************************************************/

#ifdef SNIPPET_30
#include <iostream>
#endif

#ifdef SNIPPET_31
#include <iostream>
#endif


#ifdef SNIPPET_32
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_33
#include <memory>
#include <iostream>

class myclass
{
public:
	~myclass()
	{
		std::cout << "my delete\n";
	}
};
#endif

#ifdef SNIPPET_34
#include <memory>
#include <iostream>

class myclass1
{
public:
	~myclass1()
	{
		std::cout << "my delete\n";
	}
};

class myclass2
{
	std::unique_ptr<myclass1> m_data;
public:
	myclass2() :
		m_data{std::make_unique<myclass1>()}
	{ }
};
#endif

#ifdef SNIPPET_35
#include <memory>
#include <iostream>

class myclass
{
public:
	~myclass()
	{
		std::cout << "my delete\n";
	}
};
#endif

#ifdef SNIPPET_36
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_37
#include <memory>
#include <iostream>

class int_deleter
{
public:
	void operator()(int *ptr) const
	{
		std::cout << "my delete\n";
		delete ptr;
	}
};
#endif

#ifdef SNIPPET_38
#include <memory>
#include <iostream>

using aligned_int alignas(0x1000) = int;
#endif

#ifdef SNIPPET_39
#include <memory>
#include <iostream>

struct mystruct
{
	int data{42};
};
#endif

#ifdef SNIPPET_40
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_41
#include <memory>
#include <iostream>
#endif

/****************************************************************************/
/***************************** The Answer ***********************************/
/****************************************************************************/
#ifdef SNIPPET_42
#include <memory>
#include <iostream>
#endif
/****************************************************************************/

#ifdef SNIPPET_43
#include <memory>
#include <iostream>

template<typename T> std::ostream &
operator<<(std::ostream &os, const std::unique_ptr<T> &ptr)
{
	os << ptr.get();
	return os;
}
#endif

#ifdef SNIPPET_44
#include <thread>
#include <iostream>

class myclass
{
	int m_data{0};
public:
	~myclass()
	{
		std::cout << "myclass deleted\n";
	}

	void inc()
	{ m_data++; }
};

std::thread t1;
std::thread t2;

void
thread2(myclass *ptr)
{
	for (auto i = 0; i < 10000; i++)
	{
		ptr->inc();
	}

	std::cout << "thread2: complete.\n";
}

void
thread1()
{
	auto ptr = std::make_unique<myclass>();
	t2 = std::thread(thread2, ptr.get());

	for (auto i = 0; i < 10; i++)
	{
		ptr->inc();
	}

	std::cout << "thread1: complete\n";
}

#endif

#ifdef SNIPPET_45
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_46
#include <thread>
#include <iostream>

class myclass
{
	int m_data{0};
public:
	~myclass()
	{
		std::cout << "myclass deleted\n";
	}

	void inc()
	{ m_data++; }
};

std::thread t1;
std::thread t2;

void
thread2(const std::shared_ptr<myclass> ptr)
{
	for (auto i = 0; i < 10000; i++)
	{
		ptr->inc();
	}

	std::cout << "thread2: complete.\n";
}

void
thread1()
{
	auto ptr = std::make_shared<myclass>();
	t2 = std::thread(thread2, ptr);

	for (auto i = 0; i < 10; i++)
	{
		ptr->inc();
	}

	std::cout << "thread1: complete\n";
}


#endif

#ifdef SNIPPET_47
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_48
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_49
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_50
#include <memory>
#include <iostream>
#endif

#ifdef SNIPPET_51
#include <memory>
#include <iostream>

struct mystruct {
	int data;
};
#endif

#ifdef SNIPPET_52
#include <memory>
#include <iostream>

class myclass2;

class myclass1
{
public:
	~myclass1()
	{
		std::cout << "delete myclass1\n";
	}

	std::shared_ptr<myclass2> m;
};

class myclass2
{
public:
	~myclass2()
	{
		std::cout << "delete myclass2\n";
	}

	std::shared_ptr<myclass1> m;
};

#endif

#ifdef SNIPPET_53
#include <memory>
#include <iostream>

class myclass2;

class myclass1
{
public:
	~myclass1()
	{
		std::cout << "delete myclass1\n";
	}

	std::weak_ptr<myclass2> m;
};

class myclass2
{
public:
	~myclass2()
	{
		std::cout << "delete myclass2\n";
	}

	std::weak_ptr<myclass1> m;
};

#endif

#ifdef SNIPPET_54
#include <memory>
#include <iostream>
#endif

/******************************************************************************
 *			Mapping & Permissions	
 *****************************************************************************/
#ifdef SNIPPET_55
#include <iostream>
#include <sys/mman.h>

constexpr auto PROT_RW = PROT_READ | PROT_WRITE;
constexpr auto MAP_ALLOC = MAP_PRIVATE | MAP_ANONYMOUS;

#endif

#ifdef SNIPPET_56
#include <iostream>
#include <sys/mman.h>

constexpr auto PROT_RW = PROT_READ | PROT_WRITE;
constexpr auto MAP_ALLOC = MAP_PRIVATE | MAP_ANONYMOUS;

#endif

#ifdef SNIPPET_57
#include <iostream>
#include <sys/mman.h>

constexpr auto PROT_RE = PROT_READ | PROT_EXEC;
constexpr auto MAP_ALLOC = MAP_PRIVATE | MAP_ANONYMOUS;

#endif

#ifdef SNIPPET_58
#include <iostream>
#include <sys/mman.h>

constexpr auto PROT_RW = PROT_READ | PROT_WRITE;
constexpr auto MAP_ALLOC = MAP_PRIVATE | MAP_ANONYMOUS;

#endif

#ifdef SNIPPET_59
#include <memory>
#include <iostream>

#include <sys/mman.h>
#include <string.h>

constexpr auto PROT_RW = PROT_READ | PROT_WRITE;
constexpr auto MAP_ALLOC = MAP_PRIVATE | MAP_ANONYMOUS;

class mmap_deleter
{
	std::size_t m_size;
public:
	mmap_deleter(std::size_t size) :
		m_size{size}
	{ }

	void operator()(int *ptr) const
	{
		munmap(ptr, m_size);
	}
};

template<typename T, typename... Args>
auto mmap_unique(Args&&... args)
{
	if (auto ptr = mmap(0, sizeof(T), PROT_RW, MAP_ALLOC, -1, 0))
	{
		auto obj = new (ptr) T(args...);
		auto del = mmap_deleter(sizeof(T));

		return std::unique_ptr<T, mmap_deleter>(obj, del);
	}

	throw std::bad_alloc();
}
#endif

/****************************************************************************/
/************************** Shared Memory ***********************************/
/****************************************************************************/

#ifdef SNIPPET_60
#include <memory>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>

#include <string.h>
#include <sys/mman.h>

constexpr auto PROT_RW = PROT_READ | PROT_WRITE;

auto name = "/shm";

class mmap_deleter
{
	std::size_t m_size;
public:
	mmap_deleter(std::size_t size) :
		m_size{size}
	{ }

	void operator()(int *ptr) const
	{
		munmap(ptr, m_size);
	}
};

template<typename T, typename... Args>
auto mmap_unique_server(Args&&... args)
{
	if (int fd = shm_open(name, O_CREAT | O_RDWR, 0644); fd != -1)
	{
		ftruncate(fd, sizeof(T));

		if (auto ptr = mmap(0, sizeof(T), PROT_RW, MAP_SHARED, fd, 0))
		{
			auto obj = new (ptr) T(args...);
			auto del = mmap_deleter(sizeof(T));

			return std::unique_ptr<T, mmap_deleter>(obj, del);
		}
	}

	throw std::bad_alloc();
}

template<typename T>
auto mmap_unique_client()
{
	if (int fd = shm_open(name, O_RDWR, 0644); fd != -1)
	{
		ftruncate(fd, sizeof(T));

		if (auto ptr = mmap(0, sizeof(T), PROT_RW, MAP_SHARED, fd, 0))
		{
			auto obj = static_cast<T*>(ptr);
			auto del = mmap_deleter(sizeof(T));

			return std::unique_ptr<T, mmap_deleter>(obj, del);
		}
	}

	throw std::bad_alloc();
}

#endif

/****************************************************************************/
/*--------------------------------------------------------------------------*/
int
main(void)
{

/*--------------------------------------------------------------------------*/
/*------------------------Main Logic --------------------------------------*/
/*--------------------------------------------------------------------------*/

#ifdef SNIPPET_01
	std::cout << bss_mem << '\n';
	std::cout << data_mem << '\n';
#endif

#ifdef SNIPPET_02
	int stack_mem = 42;
	std::cout << stack_mem << '\n';
#endif

#ifdef SNIPPET_03
	int stack_mem[268435456];
	std::cout << stack_mem[0] << '\n';
#endif


#ifdef SNIPPET_04
	auto ptr = new int;
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_05
	auto ptr = new int[42];
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_06
	auto ptr = new myclass[2];
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_07
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_08
	alignas(0x1000) int ptr[42];	
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_09
	char buffer[0x2000];
	auto ptr1 = reinterpret_cast<uintptr_t>(buffer);
	auto ptr2 = ptr1 - (ptr1 % 0x1000) + 0x1000;

	std::cout << std::hex << std::showbase;
	std::cout << ptr1 << '\n';
	std::cout << ptr2 << '\n';
#endif
	
#ifdef SNIPPET_10
	int *ptr;

	if (posix_memalign(reinterpret_cast<void **>(&ptr), 0x1000, 
				42 * sizeof(int))) {
		std::clog << "ERROR: unable to allocate aligned memory\n";
		::exit(EXIT_FAILURE);
	}

	std::cout << ptr << '\n';
	free(ptr);
#endif

#ifdef SNIPPET_11
	if (auto ptr = aligned_alloc(0x1000, 42 * sizeof(int))) {
		std::cout << ptr << '\n';
		free(ptr);
	}
#endif

#ifdef SNIPPET_12
	auto ptr = new aligned_int;
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_13
	auto ptr = new aligned_int[42];
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_14
	auto ptr = new (std::nothrow) int;
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_15
	auto ptr = new (std::nothrow) int[42];
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_16
	auto ptr = new (std::nothrow) aligned_int; 
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_17
	auto ptr = new (std::nothrow) aligned_int[42]; 
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_18
	auto ptr = new (std::nothrow) myclass; 
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_19
	auto ptr = new (buf) int; 
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_20
	auto ptr1 = new (buf) int; 
	auto ptr2 = new (buf) int; 
	std::cout << ptr1 << '\n';
	std::cout << ptr2 << '\n';
#endif

#ifdef SNIPPET_21
	auto ptr = new (buf) int[42]; 
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_22
	auto ptr = new (buf) int; 
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_23
	auto ptr = new (buf) int[42]; 
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_24
	auto ptr = new int; 
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_25
	auto ptr = new int[42]; 
	std::cout << ptr << '\n';
	delete [] ptr;
#endif

#ifdef SNIPPET_26
	auto ptr = new int; 
	std::cout << allocations << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_27
	auto ptr = new mystruct; 
	std::cout << allocations << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_28
	auto ptr = new myclass; 
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_29
	auto ptr1 = new aligned_myclass; 
	auto ptr2 = new aligned_myclass[42]; 
	std::cout << ptr1 << '\n';
	std::cout << ptr2 << '\n';
	delete ptr1;
	delete [] ptr2;
#endif

#ifdef SNIPPET_30
	auto ptr = new int;
	std::cout << ptr << '\n';
#endif

#ifdef SNIPPET_31
	auto ptr = new int[42];
	std::cout << ptr << '\n';
	delete ptr;
#endif

#ifdef SNIPPET_32
	auto ptr = std::make_unique<int>(42);
	std::cout << *ptr << '\n';
#endif

#ifdef SNIPPET_33
	auto ptr = std::make_unique<myclass>();
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_34
	myclass2();
	std::cout << "complete\n";
#endif

#ifdef SNIPPET_35
	std::unique_ptr<myclass[]>(new myclass[2]);
#endif

#ifdef SNIPPET_36
	auto ptr = std::make_unique<int[]>(42);
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_37
	auto ptr = std::unique_ptr<int, int_deleter>(new int, int_deleter());
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_38
	auto ptr = std::unique_ptr<int>(new aligned_int);
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_39
	auto ptr1 = std::make_unique<int>(42);
	auto ptr2 = std::make_unique<mystruct>();
	std::cout << *ptr1 << '\n';
	std::cout << ptr2->data << '\n';
#endif

#ifdef SNIPPET_40
	auto ptr = std::make_unique<int>();
	std::cout << ptr.get() << '\n';
	ptr.reset();
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_41
	auto ptr = std::make_unique<int>(42);
	if (ptr) {
		std::cout << *ptr << '\n';
	}
	ptr.reset();
	if (ptr) {
		std::cout << *ptr << '\n';
	}
#endif

#ifdef SNIPPET_42
	auto ptr = std::make_unique<int[]>(42);
	std::cout << ptr[0] << '\n';
#endif

#ifdef SNIPPET_43
	auto ptr = std::make_unique<int>();
	std::cout << ptr << '\n';
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_44
	t1 = std::thread(thread1);
	t1.join();
	t2.join();
#endif

#ifdef SNIPPET_45
	auto ptr = std::make_shared<int>();
	std::cout << ptr.get() << '\n';
#endif

#ifdef SNIPPET_46
	t1 = std::thread(thread1);
	t1.join();
	t2.join();
#endif

#ifdef SNIPPET_47
	auto ptr1 = std::make_shared<int>();
	auto ptr2 = ptr1;
	std::cout << ptr1.get() << '\n';
	std::cout << ptr2.get() << '\n';
	ptr2.reset();
	std::cout << ptr1.get() << '\n';
	std::cout << ptr2.get() << '\n';
#endif

#ifdef SNIPPET_48
	auto ptr = std::shared_ptr<int>(new int[42]());
	std::cout << ptr.get()[0] << '\n';
#endif

#ifdef SNIPPET_49
	auto ptr1 = std::make_shared<int>();
	auto ptr2 = ptr1;
	std::cout << ptr1.get() << '\n';
	std::cout << ptr2.get() << '\n';
	std::cout << ptr1.use_count() << '\n';
	ptr2.reset();
	std::cout << ptr1.get() << '\n';
	std::cout << ptr2.get() << '\n';
	std::cout << ptr1.use_count() << '\n';
#endif

#ifdef SNIPPET_50
	auto ptr = std::make_shared<int>();
	if (ptr) {
		std::cout << "before: " << ptr.get() << '\n';
	}
	ptr.reset();
	if (ptr) {
		std::cout << "after: " << ptr.get() << '\n';
	}
#endif

#ifdef SNIPPET_51
	auto ptr = std::make_shared<mystruct>();
	std::cout << ptr->data << '\n';
#endif

#ifdef SNIPPET_52
	auto ptr1 = std::make_shared<myclass1>();
	auto ptr2 = std::make_shared<myclass2>();
	ptr1->m = ptr2;
	ptr2->m = ptr1;
#endif

#ifdef SNIPPET_53
	auto ptr1 = std::make_shared<myclass1>();
	auto ptr2 = std::make_shared<myclass2>();
	ptr1->m = ptr2;
	ptr2->m = ptr1;
#endif

#ifdef SNIPPET_54
	auto ptr = std::make_unique<int>();
	std::shared_ptr<int> shared = std::move(ptr);
#endif

#ifdef SNIPPET_55
	auto ptr = mmap(0, 0x1000, PROT_RW, MAP_ALLOC, -1, 0);
	std::cout << ptr << '\n';
	munmap(ptr, 0x1000);
#endif

#ifdef SNIPPET_56
	auto ptr1 = mmap(0, 42, PROT_RW, MAP_ALLOC, -1, 0);
	auto ptr2 = mmap(0, 42, PROT_RW, MAP_ALLOC, -1, 0);
	std::cout << ptr1 << '\n';
	std::cout << ptr2 << '\n';
	munmap(ptr1, 42);
	munmap(ptr2, 42);
#endif

#ifdef SNIPPET_57
	auto ptr = mmap(0, 0x1000, PROT_RE, MAP_ALLOC, -1, 0);
	std::cout << ptr << '\n';
	munmap(ptr, 0x1000);
#endif

#ifdef SNIPPET_58
	auto ptr = mmap(0, 0x1000, PROT_RW, MAP_ALLOC, -1, 0);
	std::cout << ptr << '\n';

	if (mprotect(ptr, 0x1000, PROT_READ) == -1)
	{
		std::clog << "ERROR: Failed to change memory permissions\n";
		::exit(EXIT_FAILURE);
	}

	munmap(ptr, 0x1000);
#endif

#ifdef SNIPPET_59
	auto ptr = mmap_unique<int>(42);
	std::cout << *ptr << '\n';
#endif

#ifdef SNIPPET_60
	auto ptr1 = mmap_unique_server<int>(42);
	auto ptr2 = mmap_unique_client<int>();
	std::cout << *ptr1 << '\n';
	std::cout << *ptr2 << '\n';
#endif
	

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
}

#define CUSTOM_MANIP

/****************************************************************************/
#ifdef CUSTOMERR
#include <string.h>
#include <fcntl.h>

class custom_errno
{ };

std::ostream &operator<<(std::ostream &os, const custom_errno &e)
{
	return os << strerror(errno);
}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef MEMMAN
#include <stdio.h>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef BUF_T_CLASS 
#include <iomanip>
#include <iostream>

template<std::size_t N>
class buf_t
{
	char m_buf[N];

public:
	constexpr auto size()
	{ return N; }

	constexpr auto data()
	{ return m_buf; }
};

template<std::size_t N>
std::istream &operator>>(std::istream &is, buf_t<N> &b)
{
	is >> std::setw(b.size()) >> b.data();
	return is;
}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STRING
#include <string>
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef CUSTOMDATA
#include <iostream>

struct object_t
{
	int data1;
	int data2;
};

std::ostream &operator<<(std::ostream &os, const object_t &obj)
{
	os << "data1: " << obj.data1 << '\n';
	os << "data2: " << obj.data2 << '\n';
	return os;
}

std::istream &operator>>(std::istream &is, object_t &obj)
{
	is >> obj.data1;
	is >> obj.data2;
	return is;
}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef COMMON_DEBUG
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef DEBUG_MACRO
#include <iostream>
#ifndef NDEBUG
#define DEBUG(...) fprintf(stdout, __VA_ARGS__);
#else
#define DEBUG(...)
#endif
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef DEBUG_LEVEL_MACRO
#include <iostream>

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 1
#endif

#ifndef NDEBUG
#define DEBUG(level, ...) \
       if(level <= DEBUG_LEVEL)	fprintf(stdout, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG
#include <iostream>

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG_LEVEL
#include <iostream>

#ifdef DEBUG_LEVEL
constexpr auto g_debug_level = DEBUG_LEVEL;
#else
constexpr auto g_debug_level = 0;
#endif

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG_ENCAPSULATION
#include <iostream>

#ifdef DEBUG_LEVEL
constexpr auto g_debug_level = DEBUG_LEVEL;
#else
constexpr auto g_debug_level = 0;
#endif

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

template <std::size_t LEVEL>
constexpr void debug(void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		func();
	};
}

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C_FILE_LINE
#include <iostream>

#ifndef NDEBUG
#define DEBUG(fmt, args...) \
	fprintf(stdout, "%s [%d]: " fmt, __FILE__, __LINE__, args);
#else
#define DEBUG(...)
#endif

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_FILE_LINE
#include <iostream>

#ifdef DEBUG_LEVEL
constexpr auto g_debug_level = DEBUG_LEVEL;
#else
constexpr auto g_debug_level = 0;
#endif

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

#define console std::cout << __FILE__ << " [" << __LINE__ << "]: "

template <std::size_t LEVEL>
constexpr void debug(void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		func();
	};
}

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_COLOR_DEBUG
#include <iostream>

#ifdef DEBUG_LEVEL
constexpr auto g_debug_level = DEBUG_LEVEL;
#else
constexpr auto g_debug_level = 0;
#endif

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

#define console std::cout << __FILE__ << " [" << __LINE__ << "]: "

template <std::size_t LEVEL>
constexpr void debug(void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		std::cout << "\033[1;32mDEBUG\033[0m ";
		func();
	};
}

template <std::size_t LEVEL>
constexpr void warning(void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		std::cout << "\033[1;33mDEBUG\033[0m ";
		func();
	};
}

template <std::size_t LEVEL>
constexpr void fatal(void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		std::cout << "\033[1;31mFATAL ERROR\033[0m ";
		func();
		::exit(-1);
	};
}

template <std::size_t LEVEL>
constexpr void fatal(int error_code, void(*func)()) {
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
		std::cout << "\033[1;31mFATAL ERROR\033[0m ";
		func();
		::exit(error_code);
	};
}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STRING_STREAM

#include <iostream>
#include <sstream>

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C_LOG

#include <iostream>

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef ENDL

#include <iostream>

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef FLUSH
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef MULTILINE
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef BOOL_ALPHA
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef NUM_BASE
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef UPPER
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SHOWBASE
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef POINTER_PRINT
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_W
#include <iostream>
#include <iomanip>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_FILL
#include <iostream>
#include <iomanip>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_FILL_VARS
#include <iostream>
#include <iomanip>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STD_INTERNAL
#include <iostream>
#include <iomanip>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef COUT_FLAGS
#include <iostream>
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef COUT_RESTORE
#include <iomanip>
#include <iostream>

template<typename FUNC>
void cout_transaction(FUNC f)
{
	auto flags = std::cout.flags();
	f();
	std::cout.flags(flags);
}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef CUSTOM_MANIP
#include <iomanip>
#include <iostream>

namespace usr
{
	class hex_t { } hex;
}

std::ostream
&operator<<(std::ostream &os, const usr::hex_t &obj)
{
	os << std::hex << std::showbase << std::internal << std::setfill('0')
		<< std::setw(18);
	return os;
}
#endif
/****************************************************************************/

int main()
{
/****************************************************************************/
#ifdef STDCOUT
	std::cout << "Hello World\n";
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef OVERLOADS
	std::cout << "The answer is: " << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STDCIN 
	auto n = 0;

	std::cin >> n;
	std::cout << "input: " << n << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef CUSTOMERR
	if (open("filename.txt", O_RDWR) == -1) 
	{
		std::cout << custom_errno{} <<'\n';
	}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef CUSTOMDATA
	object_t obj;
	std::cin >> obj;
	std::cout << obj;
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef MEMMAN
	char buf[2];
	scanf("%s", buf);
	printf("\n%s", buf);

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef BUF_T_CLASS
	buf_t<2> buf;
	std::cin >> buf;

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STRING
	std::string buf;
	std::cin >> buf;
#endif
/****************************************************************************/
	
/****************************************************************************/
#ifdef COMMON_DEBUG
	std::cout << "buffered" << '\n';
	std::cout << "buffer flushed" << std::endl;
	std::cerr << "buffer flushed" << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef DEBUG_MACRO 
	DEBUG("The answer is: %d\n", 42);
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef DEBUG_LEVEL_MACRO 
	DEBUG(0,"The answer is: %d\n", 42);
	DEBUG(1,"The answer no is: %d\n", 43);
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG
	if constexpr (!g_ndebug) {
		std::cout << "The answer is :" << 42 << '\n';
	}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG_LEVEL
	if constexpr (!g_ndebug && (0 <= g_debug_level)) {
		std::cout << "The answer is :" << 42 << '\n';
	}
	if constexpr (!g_ndebug && (1 <= g_debug_level)) {
		std::cout << "The answer is not : " << 43 << '\n';
	}
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_DEBUG_ENCAPSULATION
	debug<0>([] {
		std::cout << "The answer is: " << 42 << '\n';
		});
	
	debug<1>([] {
		std::cout << "The answer is not: " << 43 << '\n';
		});
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C_FILE_LINE
	DEBUG("The answer is: %d\n", 42);
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C17_FILE_LINE
	debug<0>([] {
		console << "The answer is: " << 42 << '\n';
		});
#endif
/****************************************************************************/


/****************************************************************************/
#ifdef C17_COLOR_DEBUG
	debug<0>([] {
		console << "The answer is: " << 42 << '\n';
		});
	warning<0>([] {
		console << "The answer might be: " << 42 << '\n';
		});
	fatal<0>([] {
		console << "The answer was not: " << 42 << '\n';
		});

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STRING_STREAM
	// avoid unnecessary flushing to improve performance
	// using stringstream
	std::stringstream stream;
	stream << "The answer is: " << 42 << '\n';

	std::cout << stream.str() << std::flush;

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef C_LOG
	// output to stderr with clog
	std::clog << "The answer is: " << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef ENDL
	std::cout << "Hello World" << std::endl;
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef FLUSH
	std::cout << "Hello World\n" << std::flush;
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef MULTILINE
	std::cout << "Hello World\n";
	std::cout << "Hello World\n";
	std::cout << "Hello World\n";
	std::cout << "Hello World" << std::endl;

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef BOOL_ALPHA
	std::cout << std::boolalpha;
	std::cout << "The answer is: " << true << '\n';
	std::cout << "The answer is: " << false << '\n';

	std::cout << std::noboolalpha;
	std::cout << "The answer is: " << true << '\n';
	std::cout << "The answer is: " << false << '\n';
	
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef NUM_BASE
	std::cout << "The answer is: " << 42 << '\n' << std::hex
		<< "The answer is: " << 42 << '\n';
	std::cout << "The answer is: " << 42 << '\n' << std::dec
		<< "The answer is: " << 42 << '\n';
	std::cout << "The answer is: " << 42 << '\n' << std::oct
		<< "The answer is: " << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef UPPER
	std::cout << std::hex << std::uppercase << "The answer is: "
		<< 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SHOWBASE	
	std::cout << std::showbase;
	std::cout << std::hex << "The answer is: " << 42 << '\n';
	std::cout << std::dec<< "The answer is: " << 42 << '\n';
	std::cout << std::oct << "The answer is: " << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef POINTER_PRINT
	int i = 0;
	std::cout << &i << '\n';
	std::cout << std::hex << std::showbase << std::uppercase
		<< reinterpret_cast<uintptr_t>(&i) << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_W
	std::cout << "The answer is: " << std::setw(18) << 42 << '\n';

#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_FILL
	std::cout << "The answer is: " << std::setw(18) << std::setfill('0') 
		<< 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef SET_FILL_VARS
	std::cout << "The answer is: " << std::setw(18) << std::left 
		<< std::setfill('0') << 42 << '\n';
	std::cout << "The answer is: " << std::setw(18) << std::right 
		<< std::setfill('0') << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef STD_INTERNAL
	int i = 0;
	std::cout << std::hex
		<< std::showbase;

	std::cout << "The answer is: " << std::setw(18)  << std::internal
		<< std::setfill('0') << 42 << '\n';
	std::cout << "The answer is: " << std::setw(18)  << std::internal
		<< std::setfill('0') << &i << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef COUT_FLAGS
	auto flags = std::cout.flags();
	std::cout.flags(flags);
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef COUT_RESTORE
	cout_transaction([str = "hey there\n"]{
		std::cout << std::hex << std::showbase;
		std::cout << "The answer is: " << 42 << '\n';
		std::cout << str << '\n';
	});

	std::cout << "The answer is: " << 42 << '\n';
#endif
/****************************************************************************/

/****************************************************************************/
#ifdef CUSTOM_MANIP
	std::cout << "The answer is: " << usr::hex << 42 << '\n';
#endif
/****************************************************************************/




}


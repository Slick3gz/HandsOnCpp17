/*--------------------------------------------------------------------------*/
/*---------------- Learning to Program File Input/Output--------------------*/
/*--------------------------------------------------------------------------*/

/*######################## Active Snippet ##################################*/
#define SNIPPET_16

#define PRINTSNIPPET(x) std::cout << #x << " Result:\n--------------------\n"; 
/*##########################################################################*/

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@@@@@@@@@ Opening a File @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#ifdef SNIPPET_01
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_02
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_03
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_04
#include <fstream>
#include <iostream>
#endif


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@ Modes for Openging a File @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#ifdef SNIPPET_05
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_06
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_07
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_08
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_09
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_10
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_11
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_12
#include <fstream>
#include <iostream>
#endif

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@ Reading and Writing to a File @@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#ifdef SNIPPET_13
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_14
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_15
#include <fstream>
#include <iostream>

struct myclass
{
	std::string hello;
	std::string world;
};

std::fstream &operator>> (std::fstream &is, myclass &obj)
{
	is >> obj.hello;
	is >> obj.world;

	return is;
}

std::ostream &operator<<(std::ostream &os, myclass &obj)
{
	os << obj.hello;
	os << ' ';
	os << obj.world;

	return os;
}
#endif

/*######################## Reading Bytes ###################################*/

#ifdef SNIPPET_16
#include <iostream>
#include <fstream>
#endif

/*-------------------------------------------------------------------------*/
/*-------------------END HEADERS SECTION ----------------------------------*/
/*-------------------------------------------------------------------------*/
int main(void)
{
	
#ifdef SNIPPET_01
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << "success\n";
	}
	else
	{
		std::cout << "failure\n";
	}	
#endif

#ifdef SNIPPET_02
	if (auto file = std::fstream("test.txt"); file.is_open())
	{
		std::cout << "success\n";
	}
	else
	{
		std::cout << "failure\n";
	}
#endif

#ifdef SNIPPET_03
	auto file = std::fstream();
	if (file.open("test.txt"); file.is_open())
	{
		std::cout << "success\n";
	}
#endif

#ifdef SNIPPET_04
	std::cout << std::boolalpha;
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.is_open() << '\n';
		file.close();
		std::cout << file.is_open() << '\n';
	}
#endif

#ifdef SNIPPET_05
	constexpr auto mode = std::ios::in | std::ios::binary;
	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_06
	constexpr auto mode = std::ios::in;
	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_07
	constexpr auto mode = std::ios::out | std::ios::binary;
	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_08
	constexpr auto mode = std::ios::out;
	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_09
	constexpr auto mode = std::ios::out
		| std::ios::binary
		| std::ios::ate;

	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_10
	constexpr auto mode = std::ios::out
		| std::ios::binary
		| std::ios::app;

	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_11
	PRINTSNIPPET(SNIPPET_11)
	constexpr auto mode = std::ios::out
		| std::ios::binary
		| std::ios::ate;
	// Open file in write-only mode at the beginning of the file
	if (auto file = std::fstream("test.txt", mode); file.seekp(0))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_12
	PRINTSNIPPET(SNIPPET_12)
	constexpr auto mode = std::ios::in
		| std::ios::out
		| std::ios::trunc;
	// Open truncated file in read/write mode 
	if (auto file = std::fstream("test.txt", mode))
	{
		std::cout <<  "success\n";
	}
#endif

#ifdef SNIPPET_13
	PRINTSNIPPET(SNIPPET_13)
	if (auto file = std::fstream("test.txt"))
	{
		std::string hello, world;
		file >> hello >> world;
		std::cout << hello << " " << world << '\n';
	}
#endif

#ifdef SNIPPET_14
	PRINTSNIPPET(SNIPPET_14)
	if (auto file = std::fstream("test.txt"))
	{
		int answer;
		file >> answer;
		std::cout << "The answer is: " << answer << '\n';
	}
#endif
	
#ifdef SNIPPET_15
	PRINTSNIPPET(SNIPPET_15)
	if (auto file = std::fstream("test.txt"))
	{
		myclass obj;
		file >> obj;
		std::cout << obj << '\n';
	}
#endif
	
#ifdef SNIPPET_16
	PRINTSNIPPET(SNIPPET_16)
	if (auto file = std::fstream("test.txt"))
	{
		char c = file.get();
		std::cout << c << '\n';
	}
#endif

}

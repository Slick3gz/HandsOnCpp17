/*--------------------------------------------------------------------------*/
/*---------------- Learning to Program File Input/Output--------------------*/
/*--------------------------------------------------------------------------*/

/*######################## Active Snippet ##################################*/
#define SNIPPET_60

// Just a little macro for debugging
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

/*######################## Reading #########################################*/

#ifdef SNIPPET_16
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_17
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_18
#include <iostream>
#include <fstream>

template<typename T, std::size_t N>
void myread(std::fstream& file, T (&str)[N], std::size_t count)
{
	if (count >= N)
	{
		throw std::out_of_range("file.read out of bounds");
	}

	file.read(static_cast<char*>(str), count);	
}
#endif

#ifdef SNIPPET_19
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_20
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_21
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_22
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_23
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_24
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_25
#include <iostream>
#include <fstream>
#endif

/*######################## Writing #########################################*/

#ifdef SNIPPET_26
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_27
#include <iostream>
#include <fstream>
#endif

#ifdef SNIPPET_28
#include <iostream>
#include <fstream>

struct myclass
{
	std::string hello{"Hello"};
	std::string world{"World"};
};

std::fstream &operator<<(std::fstream &os, const myclass &obj)
{
	os << obj.hello;
	os << ' ';
	os << obj.world;

	return os;
}

#endif

#ifdef SNIPPET_29
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_30
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_31
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_32
#include <string.h>

#include <fstream>
#include <iostream>

void
mywrite(std::fstream &file, const char *str, std::size_t count)
{
	if (count > strlen(str))
	{
		throw std::out_of_range("file.write out of bounds");
	}

	file.write(str,count);
}
#endif

#ifdef SNIPPET_33
#include <string.h>

#include <fstream>
#include <iostream>

void
mywrite(std::fstream &file, const char *str, std::size_t count)
{
	if (count > strlen(str))
	{
		throw std::out_of_range("file.write out of bounds");
	}

	file.write(str,count);
}
#endif

#ifdef SNIPPET_34
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_35
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_36
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_37
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_38
#include <fstream>
#include <iostream>
#endif

#ifdef SNIPPET_39
#include <fstream>
#include <iostream>
#endif

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@ File System Utilities @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#ifdef SNIPPET_40
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_41
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_42
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_43
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_44
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_45
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_46
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_47
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_48
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_49
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_50
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_51
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_52
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_53
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_54
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_55
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_56
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_57
#include <iostream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_58
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_59
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#endif

#ifdef SNIPPET_60
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
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

#ifdef SNIPPET_17
	PRINTSNIPPET(SNIPPET_17)
	if (auto file = std::fstream("test.txt"))
	{
		char buf[25] = {};
		file.read(buf, 11);
		std::cout << buf << '\n';
	}
#endif

#ifdef SNIPPET_18
	PRINTSNIPPET(SNIPPET_18)
	if (auto file = std::fstream("test.txt"))
	{
		char buf[25] = {};
		myread(file, buf, 11);
		std::cout << buf << '\n';
	}
#endif

#ifdef SNIPPET_19
	PRINTSNIPPET(SNIPPET_19)
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.tellg() << '\n';
		char c = file.get();
		std::cout << file.tellg() << '\n';
	}
#endif

#ifdef SNIPPET_20
	PRINTSNIPPET(SNIPPET_20)
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.tellg() << '\n';
		char c = file.peek();
		std::cout << file.tellg() << '\n';
	}
#endif

#ifdef SNIPPET_21
	PRINTSNIPPET(SNIPPET_21)
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.tellg() << '\n';
		file.ignore(1);
		std::cout << file.tellg() << '\n';
	}
#endif

#ifdef SNIPPET_22
	PRINTSNIPPET(SNIPPET_22)
	if (auto file = std::fstream("test.txt"))
	{
		std::string hello, world;

		file >> hello >> world;
		std::cout << hello << " " << world << '\n';

		file.seekg(1);

		file >> hello >> world;
		std::cout << hello << " " << world << '\n';
	}
#endif

#ifdef SNIPPET_23
	PRINTSNIPPET(SNIPPET_23)
	if (auto file = std::fstream("test.txt"))
	{
		char buf[25] = {};
		file.getline(buf, 25, '\n');
		std::cout << buf << '\n';
	}
#endif

#ifdef SNIPPET_24
	PRINTSNIPPET(SNIPPET_24)
	if (auto file = std::fstream("test.txt"))
	{
		std::string str;
		std::getline(file,str);
		std::cout << str << '\n';
	}
#endif

#ifdef SNIPPET_25
	PRINTSNIPPET(SNIPPET_25)
	if (auto file = std::fstream("test.txt"))
	{
		if(file.sync() == 0)
		{
			std::cout << "success\n";
		}
		else
		{

			std::cout << "failure\n";
		}
	}
#endif

#ifdef SNIPPET_26
	PRINTSNIPPET(SNIPPET_26)
	if (auto file = std::fstream("test.txt"))
	{

		std::string hello{"Hello"}, world{"World"};
		file << hello << " " << world <<'\n';
	}
#endif

#ifdef SNIPPET_27
	PRINTSNIPPET(SNIPPET_27)
	if (auto file = std::fstream("test.txt"))
	{
		file << "The answer is: " << 42 << '\n';
	}
#endif

#ifdef SNIPPET_28
	PRINTSNIPPET(SNIPPET_28)
	if (auto file = std::fstream("test.txt"))
	{
		file << myclass{} << '\n';
	}
#endif

#ifdef SNIPPET_29
	PRINTSNIPPET(SNIPPET_29)
	if (auto file = std::fstream("test.txt"))
	{
		file.put('H');
		file.put('\n');
	}
#endif
	
#ifdef SNIPPET_30
	PRINTSNIPPET(SNIPPET_30)
	if (auto file = std::fstream("test.txt"))
	{
		file.write("Hello World\n", 12);
	}
#endif

#ifdef SNIPPET_31
	PRINTSNIPPET(SNIPPET_31)
	if (auto file = std::fstream("test.txt"))
	{
		// Unsafe
		file.write("Hello World\n", 100);
	}
#endif


#ifdef SNIPPET_32
	PRINTSNIPPET(SNIPPET_32)
	if (auto file = std::fstream("test.txt"))
	{
		mywrite(file, "Hello World\n", 100);
	}
#endif

#ifdef SNIPPET_33
	PRINTSNIPPET(SNIPPET_33)
	if (auto file = std::fstream("test.txt"))
	{
		const char str1[6] = {'H','e','l','l','o','\n'};
		const char str2[6] = {'W','o','r','l','d','\n'};
		mywrite(file, str1, 12);
	        mywrite(file, str2, 6);	
	}
#endif

#ifdef SNIPPET_34
	PRINTSNIPPET(SNIPPET_34)
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.tellp() << '\n';
		file << "Hello";
		std::cout << file.tellp() << '\n';
		file << ' ';
		std::cout << file.tellp() << '\n';
		file << "World";
		std::cout << file.tellp() << '\n';
		file << '\n';
		std::cout << file.tellp() << '\n';
	}
#endif

#ifdef SNIPPET_35
	PRINTSNIPPET(SNIPPET_35)
	if (auto file = std::fstream("test.txt"))
	{
		std::cout << file.tellp() << '\n';
		file << "Hello World\n";
		std::cout << file.tellp() << '\n';
		file.seekp(0);
		file << "The answer is : " << 42 << '\n';
		std::cout << file.tellp() << '\n';
	}
#endif

#ifdef SNIPPET_36
	PRINTSNIPPET(SNIPPET_36)
		
	std::cout << std::boolalpha;

	if (auto file = std::fstream("test.txt"))
	{

		std::string hello{"Hello"}, world{"World"};
		file << hello << " " << world << '\n';
		std::cout << "good: " << file.good() << '\n';
		std::cout << "fail: " << file.fail() << '\n';
		std::cout << "bad: " << file.bad() << '\n';
		std::cout << "eof: " << file.eof() << '\n';
	}

#endif

#ifdef SNIPPET_37
	PRINTSNIPPET(SNIPPET_37)
		
	std::cout << std::boolalpha;

	if (auto file = std::fstream("test.txt"))
	{
		std::string hello{"Hello"}, world{"World"};
		file << hello << " " << world << '\n';
		if (!file)
		{
			std::cout << "failed\n";
		}
	}

#endif

#ifdef SNIPPET_38
	PRINTSNIPPET(SNIPPET_38)
		
	std::cout << std::boolalpha;

	if (auto file = std::fstream("test.txt"))
	{
		std::string hello{"Hello"}, world{"World"};
		file << hello << " " << world << '\n';
		if (file)
		{
			std::cout << "success\n";
		}
	}

#endif

#ifdef SNIPPET_39
	PRINTSNIPPET(SNIPPET_39)
		
	std::cout << std::boolalpha;

	if (auto file = std::fstream("test.txt"))
	{
		int answer;
		std::cout << file.good() << '\n';
		file >> answer;
		std::cout << file.good() << '\n';
		file.clear();
		std::cout << file.good() << '\n';
	}

#endif

#ifdef SNIPPET_40
	PRINTSNIPPET(SNIPPET_40)

	using namespace std::experimental::filesystem;

	std::cout << std::boolalpha;
	std::cout << "is_block_file: " << is_block_file("/dev/sda1") << '\n';
	std::cout << "is_character_file: " << is_character_file("/dev/random") << '\n';
	std::cout << "is_directory: " << is_directory("/dev") << '\n';
	std::cout << "is_empty: " <<  is_empty("/dev") << '\n';
	std::cout << "is_fifo: " << is_fifo("scratchpad.cpp") << '\n';
	std::cout << "is_socket: " << is_socket("scratchpad.cpp") << '\n';
	std::cout << "is_symlink: " << is_symlink("scratchpad.cpp") << '\n';


#endif

#ifdef SNIPPET_41
	PRINTSNIPPET(SNIPPET_41)

	using namespace std::experimental::filesystem;

	std::cout << std::boolalpha;
	std::cout << "Exists (/dev): " << exists("/dev") << '\n';
	std::cout << "Exists (/dev/random): " << exists("/dev/random") << '\n';
	std::cout << "Exists (scratchpad.cpp): " << exists("scratchpad.cpp") << '\n';

#endif

#ifdef SNIPPET_42
	PRINTSNIPPET(SNIPPET_42)

	using namespace std::experimental::filesystem;

	std::cout << "Current Path -> " << current_path() << '\n';

#endif

#ifdef SNIPPET_43
	PRINTSNIPPET(SNIPPET_43)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	std::cout << "Current absolute path: " << path << '\n';
	// Following line doesn't work because of implementation
	//std::cout << "Current relative path: " << relative(path) << '\n';

#endif

#ifdef SNIPPET_44
	PRINTSNIPPET(SNIPPET_44)

	using namespace std::experimental::filesystem;

	std::cout << canonical(".") << '\n';
	std::cout << canonical("../chap8") << '\n';

#endif

#ifdef SNIPPET_45
	PRINTSNIPPET(SNIPPET_45)

	using namespace std::experimental::filesystem;

	std::cout << absolute("../chap8") << '\n';

#endif

#ifdef SNIPPET_46
	PRINTSNIPPET(SNIPPET_46)

	using namespace std::experimental::filesystem;

	auto path1 = path{"."};
	auto path2 = path{"../chap8"};
	auto path3 = path{"../chap8/../chap8"};
	auto path4 = current_path();
	auto path5 = current_path() / "../chap8/";

	std::cout << std::boolalpha;
	std::cout << equivalent(path1, path2) << '\n';
	std::cout << equivalent(path1, path3) << '\n';
	std::cout << equivalent(path1, path4) << '\n';
	std::cout << equivalent(path1, path5) << '\n';
#endif

#ifdef SNIPPET_47
	PRINTSNIPPET(SNIPPET_47)

	using namespace std::experimental::filesystem;

	auto path1 = path{"."};
	auto path2 = path{"../chap8"};
	auto path3 = path{"../chap8/../chap8"};
	auto path4 = current_path();
	auto path5 = current_path() / "../chap8/";

	std::cout << std::boolalpha;
	std::cout << (path1 == path2) << '\n';
	std::cout << (path1 == path3) << '\n';
	std::cout << (path1 == path4) << '\n';
	std::cout << (path1 == path5) << '\n';
#endif

#ifdef SNIPPET_48
	PRINTSNIPPET(SNIPPET_48)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << path << '\n';
#endif

#ifdef SNIPPET_49
	PRINTSNIPPET(SNIPPET_49)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path += "/scratchpad.cpp";

	std::cout << path << '\n';
#endif

#ifdef SNIPPET_50
	PRINTSNIPPET(SNIPPET_50)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << path << '\n';

	path.remove_filename();

	std::cout << path << '\n';

#endif

#ifdef SNIPPET_51
	PRINTSNIPPET(SNIPPET_51)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << path << '\n';

	path.replace_filename("test.cpp");

	std::cout << path << '\n';

#endif

#ifdef SNIPPET_52
	PRINTSNIPPET(SNIPPET_52)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << path << '\n';

	path.replace_extension("txt");

	std::cout << path << '\n';

#endif

#ifdef SNIPPET_53
	PRINTSNIPPET(SNIPPET_53)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << path << '\n';

	path.clear();

	std::cout << path << '\n';

#endif


#ifdef SNIPPET_54
	PRINTSNIPPET(SNIPPET_54)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << std::boolalpha;

	std::cout << path.root_name() << '\n';
	std::cout << path.root_directory() << '\n';
	std::cout << path.root_path() << '\n';
	std::cout << path.relative_path() << '\n';
	std::cout << path.parent_path() << '\n';
	std::cout << path.filename() << '\n';
	std::cout << path.stem() << '\n';
	std::cout << path.extension() << '\n';

#endif

#ifdef SNIPPET_55
	PRINTSNIPPET(SNIPPET_55)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "scratchpad.cpp";

	std::cout << std::boolalpha;

	std::cout << path.empty() << '\n';
	std::cout << path.has_root_path() << '\n';
	std::cout << path.has_root_name() << '\n';
	std::cout << path.has_root_directory() << '\n';
	std::cout << path.has_relative_path() << '\n';
	std::cout << path.has_parent_path() << '\n';
	std::cout << path.has_filename() << '\n';
	std::cout << path.has_stem() << '\n';
	std::cout << path.has_extension() << '\n';
	std::cout << path.is_absolute() << '\n';
	std::cout << path.is_relative() << '\n';

#endif

#ifdef SNIPPET_56
	PRINTSNIPPET(SNIPPET_56)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "test";

	std::cout << std::boolalpha;

	std::cout << create_directory(path) << '\n';
	std::cout << remove(path) << '\n';

#endif

#ifdef SNIPPET_57
	PRINTSNIPPET(SNIPPET_57)

	using namespace std::experimental::filesystem;

	auto path1 = current_path();
	auto path2 = current_path();

	path1 /= "test1";
	path2 /= "test2";

	std::cout << std::boolalpha;

	std::cout << create_directory(path1) << '\n';
	rename(path1, path2);
	std::cout << remove(path1) << '\n';
	std::cout << remove(path2) << '\n';

#endif

#ifdef SNIPPET_58
	PRINTSNIPPET(SNIPPET_58)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "test";

	std::cout << std::boolalpha;

	std::cout << create_directory(path) << '\n';

	std::fstream(path / "test1.txt", std::ios::app);
	std::fstream(path / "test2.txt", std::ios::app);
	std::fstream(path / "test3.txt", std::ios::app);

	std::cout << remove_all(path) << '\n';

#endif

#ifdef SNIPPET_59
	PRINTSNIPPET(SNIPPET_59)

	using namespace std::experimental::filesystem;

	auto path = current_path();

	path /= "test";

	std::cout << std::boolalpha;

	std::cout << create_directory(path) << '\n';

	std::fstream(path / "test1.txt", std::ios::app);
	std::fstream(path / "test2.txt", std::ios::app);
	std::fstream(path / "test3.txt", std::ios::app);

	for(const auto &p: directory_iterator(path))
	{
		std::cout << p << '\n';
	}

	std::cout << remove_all(path) << '\n';

#endif

#ifdef SNIPPET_60
	PRINTSNIPPET(SNIPPET_60)

	using namespace std::experimental::filesystem;
	
	std::cout << temp_directory_path() << '\n';
#endif
}


#include <iostream>
#include <sstream>
#include <fstream>

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

std::fstream g_log{"log.txt", std::ios::out | std::ios::app};

template <std::size_t LEVEL>
constexpr void log(void(*func)())
{
	if constexpr (!g_ndebug && (LEVEL <= g_debug_level))
	{
		std::stringstream buf;
		auto g_buf = std::clog.rdbuf();
		std::clog.rdbuf(buf.rdbuf());

		func();

		std::clog.rdbuf(g_buf);

		std::clog << "\033[1;32mDEBUG\033[0m: ";
		std::clog << buf.str();

		
		g_log << "\033[1;32mDEBUG\033[0m: ";
		g_log << buf.str();
	};
}


int
protected_main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	log<0>([] {
			std::clog << "Hello World\n";
		});

	std::clog << "Hello World from protected main\n";
	
	return EXIT_SUCCESS;
}


int
main(int argc, char **argv)
{
	try {
		return protected_main(argc, argv);
	}
	catch (const std::exception &e) {
		std::cerr << "Caught unhandled exception:\n";
		std::cerr << " - what(): " << e.what() << '\n';
	}
	catch(...)
	{
		std::cerr << "Caught unknown exception\n";
	}

	return EXIT_FAILURE;
}

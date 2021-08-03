#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#include <iostream>
#include <fstream>
#include <chrono>


constexpr auto size = 0x1000;

template<typename FUNC>
auto benchmark(FUNC func)
{

	auto stime = std::chrono::high_resolution_clock::now();
	func();
	auto etime = std::chrono::high_resolution_clock::now();

	return etime - stime;
}

int
protected_main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	using namespace std::chrono;
	{
		char buf[size] = {};
		if (auto file = std::fstream("test.txt", std::ios::out))
		{
			file.write(buf, size);
		}
	}

	{
		char buf[size] = {};
		if (auto file = std::fstream("test.txt", std::ios::in))
		{
			auto time = benchmark([&file, &buf]{
					file.read(buf, size);
			});

			std::cout << "c++ time: "
				<< duration_cast<microseconds>(time).count()
				<< '\n';
		}
	}

	{
		void *buf;
		if (int fd = open("test.txt", O_RDONLY); fd != 0)
		{
			auto time = benchmark([&fd, &buf]{
					buf = mmap(NULL, size, PROT_READ, 0, fd, 0);
			});

			munmap(buf, size);
			std::cout << "mmap time: "
				<< duration_cast<microseconds>(time).count()
				<< '\n';
		}
	}

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

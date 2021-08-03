#include <iostream>
#include <fstream>
#include <unistd.h>
#include <gsl/gsl-lite.hpp>

using namespace gsl;

constexpr auto mode = std::ios::in | std::ios::ate;

[[noreturn]] void
tail(std::fstream &file)
{
	while (true)
	{
		file.peek();

		while (!file.eof())
		{
			auto pos = file.tellg();

			std::string buf;
			std::getline(file, buf, '\n');

			if (file.eof() && !file.good())
			{
				file.seekg(pos);
				break;
			}

			std::cout << buf << '\n';
		}

		sleep(1);
		file.clear();
		file.sync();
	}
}

int
protected_main(int argc, char **argv)
{
	std::string filename;
	auto args = make_span(argv, argc);

	if (args.size() < 2) 
	{
		std::cin >> filename;
	}
	else
	{
		filename = ensure_z(args[1]).data();
	}

	if (auto file = std::fstream(filename, mode))
	{
		tail(file);
	}

	throw std::runtime_error("failed to open file");
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

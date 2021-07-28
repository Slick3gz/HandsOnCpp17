#include <fstream>
#include <functional>
#include <iostream>
#include <gsl/gsl-lite.hpp>

using namespace gsl;

void
redirect_output(
		const std::ifstream &is,
		const std::ofstream &os,
		std::function<void()> f)
{
	auto cinrdbuf = std::cin.rdbuf();
	auto coutrdbuf = std::cout.rdbuf();

	std::cin.rdbuf(is.rdbuf());
	std::cout.rdbuf(os.rdbuf());

	f();

	std::cin.rdbuf(cinrdbuf);
	std::cout.rdbuf(coutrdbuf);
}

auto
open_streams(cstring_span port)
{
	std::ifstream is(port.data());
	std::ofstream os(port.data());

	if (!is || !os) {
		std::clog << "ERROR: unable to open serial port:" 
			<< port.data()
			<< '\n';
		::exit(EXIT_FAILURE);
	}

	return std::make_pair(std::move(is), std::move(os));
}

int
protected_main(int argc, char **argv)
{
	auto args = make_span(argv, argc);

	if (argc != 2) {
		std::clog << "ERROR: unsupported number of arguments\n";
		::exit(EXIT_FAILURE);
	}

	auto [is, os] = open_streams(
			ensure_z(args[1])
	);

	redirect_output(is, os, [] {
			std::string buf;

			std::cin >> buf;
			std::cout << buf << std::flush;
			});

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

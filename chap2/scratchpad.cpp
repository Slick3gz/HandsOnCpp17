#include <iostream>

int main()
{
	void *ptr;

	if (posix_memalign(&ptr, 0x1000, 42 * sizeof(int))) {
		std::clog << "ERROR: unable to allocate aligned memory\n";
		::exit(EXIT_FAILURE);
	}

	std::cout << ptr << '\n';
	free(ptr);
}

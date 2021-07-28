#include <iostream>

#pragma pack(push, 1)
struct mystruct {
	uint16_t *data1;
	uint64_t data2;
};
#pragma pack(pop)

int main()
{
	std::cout  << "size: " << sizeof(mystruct) << '\n';
}

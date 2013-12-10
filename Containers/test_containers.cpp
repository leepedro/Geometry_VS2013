#include "containers.h"

int main(void)
{
	std::array<int, 2> array1 = { 1, 2 }, array2 = { 3, 4 };
	using namespace Imaging;
	std::array<int, 2> array3 = array1 + array2;
}
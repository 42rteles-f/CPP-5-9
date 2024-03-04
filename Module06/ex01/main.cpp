
#include "Serializer.hpp"
/*
missing tests.

*/
int	main(void)
{
	Data		structure;
	uintptr_t	ptr;

	ptr = Serializer::serialize(&structure);
	std::cout << ((Serializer::deserialize(ptr) == &structure) ?
					"Equal Pointers" : "Different Pointers") << std::endl;
}
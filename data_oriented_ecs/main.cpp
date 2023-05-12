#include <iostream>
#include <bitset>

#include "common.h"
#include "id.h"

int main()
{
	std::cout << "id_type:               " << sizeof(ecs::id::id_type) * 8 << " bits" << std::endl;
	std::cout << "generation:            " << ecs::id::generation_bits << " bits" << std::endl;
	std::cout << "index:                 " << ecs::id::index_bits << " bits" << std::endl;
	std::cout << "index mask bits:       " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::index_mask) << std::endl;
	std::cout << "generation mask:       " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::generation_mask) << std::endl;
	std::cout << "id mask:               " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::id_mask) << std::endl;
	std::cout << "max generation value:  " << ecs::id::max_value_generation << std::endl;
	std::cout << "max index value:       " << ecs::id::max_value_index << std::endl;
	std::cout << "generation type:       u" << sizeof(ecs::id::generation_type) * 8 << std::endl;

	return EXIT_SUCCESS;
}
#include <iostream>
#include <bitset>

#include "common.h"
#include "id.h"

int main()
{
	std::cout << "id_type:                              " << sizeof(ecs::id::id_type) * 8 << " bits" << std::endl;
	std::cout << "generation:                           " << ecs::id::generation_bits << " bits" << std::endl;
	std::cout << "index:                                " << ecs::id::index_bits << " bits" << std::endl;
	std::cout << "index mask bits:                      " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::index_mask) << std::endl;
	std::cout << "generation mask:                      " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::generation_mask) << std::endl;
	std::cout << "id mask:                              " << std::bitset<sizeof(ecs::id::id_type) * 8>(ecs::id::id_mask) << std::endl;
	std::cout << "max generation value:                 " << ecs::id::max_value_generation << std::endl;
	std::cout << "max index value:                      " << ecs::id::max_value_index << std::endl;
	std::cout << "generation type:                      u" << sizeof(ecs::id::generation_type) * 8 << std::endl;

	std::cout << "\ncreating entity..." << std::endl;
	ecs::id::id_type entity{ std::numeric_limits<ecs::id::id_type>::max() ^ ecs::id::generation_mask };
	std::cout << "entity id value:                      " << entity << std::endl;
	std::cout << "entity id bits:                       " << std::bitset<sizeof(ecs::id::id_type) * 8>(entity) << std::endl;
	std::cout << "entity is valid:                      " << (ecs::id::is_valid(entity) ? "true" : "false") << std::endl;
	std::cout << "entity index:                         " << ecs::id::index(entity) << std::endl;
	std::cout << "entity generation:                    " << ecs::id::generation(entity) << std::endl;

	std::cout << "\nincrementing entity generation..." << std::endl;
	for (int i = 0; i < 254; ++i)
		entity = ecs::id::new_generation(entity);

	std::cout << "new generation entity id value:       " << entity << std::endl;
	std::cout << "new generation entity id bits:        " << std::bitset<sizeof(ecs::id::id_type) * 8>(entity) << std::endl;
	std::cout << "new generation entity is valid:       " << (ecs::id::is_valid(entity) ? "true" : "false") << std::endl;
	std::cout << "new generation entity index:          " << ecs::id::index(entity) << std::endl;
	std::cout << "new generation entity generation:     " << ecs::id::generation(entity) << std::endl;

	return EXIT_SUCCESS;
}
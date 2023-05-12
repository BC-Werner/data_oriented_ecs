#pragma once

#include "common.h"

namespace ecs::id {

	using id_type = u32;

	constexpr u32 generation_bits{ 8 };
	constexpr u32 index_bits{ sizeof(id_type) * 8 - generation_bits };

	constexpr id_type generation_mask{ ((id_type{1} << generation_bits) - 1) << index_bits };
	constexpr id_type index_mask{ (id_type{1} << index_bits) - 1 };
	constexpr id_type id_mask{ std::numeric_limits<id_type>::max() };

	constexpr id_type max_value_generation{ (generation_mask >> index_bits) };
	constexpr id_type max_value_index{ index_mask };

	using generation_type = std::conditional< (generation_bits > 16), u32, std::conditional< (generation_bits > 8), u16, u8 >::type >::type;
	static_assert(sizeof(generation_type) * 8 >= generation_bits, "Generation bits must fit within a maximum of 32 bits");
	static_assert((sizeof(id_type) - sizeof(generation_type)) > 0, "Generation bits must be less than total id bits");

	inline bool is_valid(id_type id)
	{
		return id != id_mask;
	}

	inline id_type index(id_type id)
	{
		return id & index_mask;
	}
	
	inline id_type generation(id_type id)
	{
		return (id & generation_mask) >> index_bits;
	}

	inline id_type new_generation(id_type id)
	{
		const id_type generation{ id::generation(id) + 1};
		assert(generation < max_value_generation);
		return id::index(id) | (generation << index_bits);
	}

}

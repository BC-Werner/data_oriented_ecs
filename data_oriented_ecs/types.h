#pragma once

#include <stdint.h>

// Unsigned
using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// Signed
using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

// Float
using f32 = float;

// Invalid id types
constexpr u8  invalid_id_u8  = 0xffui8;
constexpr u16 invalid_id_u16 = 0xffffui16;
constexpr u32 invalid_id_u32 = 0xffff'ffffui32;
constexpr u64 invalid_id_u64 = 0xffff'ffff'ffffui64;

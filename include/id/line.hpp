#ifndef NEPOMUK_ID_LINE_HPP_
#define NEPOMUK_ID_LINE_HPP_

#include "tool/types_and_traits/strong_typedef.hpp"

namespace nepomuk
{
STRONG_ID_TYPE(std::uint64_t, LineID)

auto const constexpr WALKING_TRANSFER = LineID{static_cast<std::uint64_t>(-1)};
} // namespace nepomuk

// needs to be outside of nepomuk namespace to ingest into std namespace
STRONG_ID_TYPE_HASH(std::uint64_t, nepomuk::LineID)

#endif // NEPOMUK_ID_LINE_HPP_

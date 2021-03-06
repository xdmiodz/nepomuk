#include "timetable/duration_table.hpp"
#include <boost/assert.hpp>

namespace nepomuk
{
namespace timetable
{

std::uint32_t DurationTable::prefix_time(std::size_t const offset) const
{
    BOOST_ASSERT(offset < arrival_prefix.size());
    return arrival_prefix[offset];
}

std::uint32_t DurationTable::duration(std::size_t const offset) const
{
    BOOST_ASSERT(offset < arrival_delta.size());
    return arrival_delta[offset];
}

// list stations along the line, and their departure
DurationTable::const_iterator_range DurationTable::list(std::size_t const offset) const
{
    return boost::make_iterator_range<const_iterator>(arrival_delta.begin() + offset,
                                                      arrival_delta.end());
}

bool operator==(DurationTable const &lhs, DurationTable const &rhs)
{
    return lhs.arrival_delta == rhs.arrival_delta;
}

} // namespace timetable
} // namespace nepomuk

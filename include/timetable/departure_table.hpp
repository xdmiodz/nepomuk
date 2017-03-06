#ifndef TRANSIT_TIMETABLE_DEPARTURETABLE_HPP_
#define TRANSIT_TIMETABLE_DEPARTURETABLE_HPP_

#include <cstdint>

#include <boost/range/iterator_range.hpp>

#include "gtfs/time.hpp"
#include "gtfs/trip.hpp"

namespace transit
{
namespace timetable
{

class DepartureTableFactory;

// Public transit routing consists of timetable routing. The departuretables define when connections
// leave certain stops. In general these occurr in certain periodic settings. For any time at any
// stop we need to be able to access the next connections that are possible. The departuretable
// itself assumes the stop, line, and the time of arrival are known and allows  quick access to the
// next connection of the given departure. It only represents a single line.
class DepartureTable
{
  public:
    struct Departure
    {
        gtfs::Time begin;
        gtfs::Time end;
        std::uint32_t headway;

        bool operator<(Departure const &other) const;

        gtfs::Time getNextDeparture(gtfs::Time const starting_at) const;
    };

    // iterator types
    using const_iterator = std::vector<Departure>::const_iterator;
    using const_iterator_range = boost::iterator_range<const_iterator>;

    // access for construction
    friend class DepartureTableFactory;

    // access methods
    gtfs::TripID trip_id() const { return _trip_id; }

    // list all valid departures from a given time
    const_iterator_range list(gtfs::Time starting_at) const;

  private:
    gtfs::TripID _trip_id;
    std::vector<Departure> departures;
};

} // namespace timetable
} // namespace transit

#endif // TRANSIT_TIMETABLE_DEPARTURETABLE_HPP_
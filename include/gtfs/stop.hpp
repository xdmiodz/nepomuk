#ifndef NEPOMUK_GTFS_STOP_HPP_
#define NEPOMUK_GTFS_STOP_HPP_

#include <boost/optional.hpp>

#include <cstddef>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "date/time.hpp"
#include "geometric/coordinate.hpp"
#include "gtfs/accessibility.hpp"
#include "id/dictionary.hpp"
#include "id/sequence.hpp"
#include "id/stop.hpp"
#include "id/trip.hpp"
#include "id/zone.hpp"

namespace nepomuk
{

namespace tool
{
namespace container
{
class Dictionary;
}
}

namespace gtfs
{

enum class LocationType
{
    STOP,
    STATION
};

struct Stop
{
    StopID id;
    DictionaryID name;
    geometric::WGS84Coordinate location;

    // optional additional features
    boost::optional<std::string> code;
    boost::optional<DictionaryID> description;
    boost::optional<ZoneID> zone_id;
    boost::optional<DictionaryID> url;
    boost::optional<LocationType> location_type;
    boost::optional<StopID> parent_station;
    boost::optional<std::string> timezone;
    boost::optional<accessibility::Wheelchair> wheelchair_access;
};

bool checkStopCSVHeader(std::map<std::string, std::size_t> const &header);
Stop makeStop(std::map<std::string, std::size_t> const &header,
              std::vector<std::string> &values,
              tool::container::Dictionary &dictionary);

enum class StopType
{
    REGULAR,
    NOT_AVAILABLE,
    PHONE_AGENCY,
    COORDINATE_DRIVER
};

enum class TimepointType
{
    EXACT,
    APPROXIMATE
};

// noon - 12 times
struct StopTime
{
    TripID trip_id;
    date::Time arrival;
    date::Time departure;
    StopID stop_id;
    SequenceID sequence_id;

    // optional additional features
    boost::optional<std::string> headsign;
    boost::optional<StopType> pickup_type;
    boost::optional<StopType> drop_off_type;
    boost::optional<double> shape_distance_traveled;
    boost::optional<TimepointType> timepoint;
};

bool checkStopTimeCSVHeader(std::map<std::string, std::size_t> const &header);
StopTime makeStopTime(std::map<std::string, std::size_t> const &header,
                      std::vector<std::string> &values);

} // namespace gtfs
} // namespace nepomuk

#endif // NEPOMUK_GTFS_STOP_HPP_

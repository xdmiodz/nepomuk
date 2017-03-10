#ifndef TRANSIT_NAVIGATION_ROUTING_ALGORITHM_HPP
#define TRANSIT_NAVIGATION_ROUTING_ALGORITHM_HPP

#include "gtfs/stop.hpp"
#include "gtfs/time.hpp"
#include "navigation/trip.hpp"
#include "navigation/leg.hpp"

namespace transit
{
namespace navigation
{

// interface for all routing algorithms to implement
class RoutingAlgorithm
{
  public:
    virtual Trip operator()(gtfs::Time const departure,
                            gtfs::StopID const origin,
                            gtfs::StopID const destination) const = 0;

  protected:
    void add_leg(Trip &trip, Leg leg) const;
    void add_stop(Leg &leg, Leg::stop_type stop) const;
    void set_departure(Leg &leg, gtfs::Time time) const;
};

} // namespace navigation
} // namespace transit

#endif // TRANSIT_NAVIGATION_ROUTING_ALGORITHM_HPP
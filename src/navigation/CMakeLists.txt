# define a set of sources to compile
SET(navigation_SOURCES
    stop.cpp
    connection.cpp
    segment.cpp
    leg.cpp
    route.cpp
    routing_algorithm.cpp
    algorithm/timetable.cpp
    algorithm/timetable_dijkstra.cpp)

# export source files as library
ADD_LIBRARY(NEPOMUKnavigation
    ${navigation_SOURCES})

# link all required items
TARGET_LINK_LIBRARIES(NEPOMUKnavigation
    ${Boost_LIBRARIES}
    ${MAYBE_COVERAGE_LIBRARIES})

# define additional include directories
TARGET_INCLUDE_DIRECTORIES(NEPOMUKnavigation SYSTEM PUBLIC
    ${Boost_INCLUDE_DIRS})

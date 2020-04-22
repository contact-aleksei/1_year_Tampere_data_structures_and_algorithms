Aleksei
293200

For the given project I used two unordered maps to save regions and stops. StopsID and RegionsID for
saving the value and key in Stops and Regions. Also, I used Distances struct to save distances between
the stops.

The unordered map has average performance O(n) to search, add, and remove. I used these
operations in other functions, for instance, finding the StopsID or RegionsID when doing other
operations.

Data structure was used for sorting instead of built-in functions of sort vector of C++. Based on
observations, the performance improves when converting from one data structure to another.

The functions' performances are described in header file datastructures.hh as estimate of
performance and short rationale for estimate.

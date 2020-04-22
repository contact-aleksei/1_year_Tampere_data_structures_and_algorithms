// Datastructures.cc

#include "datastructures.hh"
using namespace std;
using namespace std;
#include <iostream>
#include <random>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>


std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Replace this comment with your implementation

}

Datastructures::~Datastructures()
{
    // Replace this comment with your implementation
}

int Datastructures::stop_count()
{
    // Replace this comment and the line below with your implementation
    //return NO_VALUE;

    //int number_of_stops;
    //number_of_stops=stops_map.size();
    return number_of_stops;
}

void Datastructures::clear_all()
{
    // Replace this comment with your implementation
    stops_map.clear();
    number_of_stops=0;
}

std::vector<StopID> Datastructures::all_stops()
{
    // Replace this comment and the line below with your implementation
    //return {NO_STOP}; 
    StopID stop_that_is_to_be_pushed;
        std::vector<StopID> stops_vector;
        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            stop_that_is_to_be_pushed = stops_iterator->first;
            stops_vector.push_back(stop_that_is_to_be_pushed);
        }
        return stops_vector;
}

bool Datastructures::add_stop(StopID id, const Name& name, Coord xy)
{
    // Replace this comment and the line below with your implementation
    //return false;

    if (!find_id_stops(id))           // if the StopID has been already added before
    {
        std::shared_ptr<Stops> new_stop = std::make_shared<Stops>();

        new_stop->id = id;
        new_stop->name = name;
        new_stop->coord = xy;

        stops_map[id] = new_stop;
        number_of_stops += 1;

        return true;
    }
    else
    {
        return false;
    }
}

Name Datastructures::get_stop_name(StopID id)
{
    // Replace this comment and the line below with your implementation
    //return NO_NAME;
    if (find_id_stops(id))
        {
            std::shared_ptr<Stops> stops_pointer = stops_map[id];
            return stops_pointer->name;
        }
    else
        {
            return NO_NAME;
        }
}

Coord Datastructures::get_stop_coord(StopID id)
{
    // Replace this comment and the line below with your implementation
    // return NO_COORD;
    if (find_id_stops(id))
        {
            std::shared_ptr<Stops> stops_pointer = stops_map[id];
            return stops_pointer->coord;
        }
        else
        {
            return NO_COORD;
        }
}

std::vector<StopID> Datastructures::stops_alphabetically()
{
    // Replace this comment and the line below with your implementation
    // return {NO_STOP};

    std::multimap<std::string, StopID> stops_alphabetically_map;

            std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                    stops_iterator = stops_map.begin();
            for (;stops_iterator != stops_map.end(); stops_iterator++)
            {
                StopID id = stops_iterator->first;
                std::string name = get_stop_name(id);
                stops_alphabetically_map.insert(std::pair<std::string, StopID>(name,id));
            }

            std::vector<StopID> stops_alphabetically_vector;
            std::multimap<std::string, StopID>::const_iterator multimap_iterator
                    = stops_alphabetically_map.begin();
            for (;multimap_iterator != stops_alphabetically_map.end(); multimap_iterator++)
            {
                stops_alphabetically_vector.push_back(multimap_iterator->second);
            }
            return stops_alphabetically_vector;
}

std::vector<StopID> Datastructures::stops_coord_order()
{
    // Replace this comment and the line below with your implementation
    // return {NO_STOP};

        std::multimap<double, StopID> stops_coord_map;

        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            StopID id = stops_iterator->first;
            double coordinate_order = for_coordinates_ordering(id);
            stops_coord_map.insert(std::pair<int, StopID>(coordinate_order,id));
        }

        std::vector<StopID> stops_coord_vector;
        std::multimap<double, StopID>::const_iterator
                map_iterator = stops_coord_map.begin();
        for (;map_iterator != stops_coord_map.end(); map_iterator++)
        {
            stops_coord_vector.push_back(map_iterator->second);
        }
        return stops_coord_vector;
}

StopID Datastructures::min_coord()
{
    // Replace this comment and the line below with your implementation
    // return NO_STOP;


    if (number_of_stops != 0)
        {
        std::multimap<float, StopID> stops_coord_map;

        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            StopID id = stops_iterator->first;
            float coordinate_order = for_coordinates_ordering(id);
            stops_coord_map.insert(std::pair<int, StopID>(coordinate_order,id));
        }

        std::vector<StopID> stops_coord_vector;
        std::multimap<float, StopID>::const_iterator
                map_iterator = stops_coord_map.begin();
        for (;map_iterator != stops_coord_map.end(); map_iterator++)
        {
            stops_coord_vector.push_back(map_iterator->second);
        }
        return stops_coord_vector[0];
        }
        else
        {
            return NO_STOP;
        }
}


StopID Datastructures::max_coord()
{
    // Replace this comment and the line below with your implementation
    // return NO_STOP;
    if (number_of_stops != 0)
        {
        std::multimap<float, StopID> stops_coord_map;

        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            StopID id = stops_iterator->first;
            double coordinate_order = for_coordinates_ordering(id);
            stops_coord_map.insert(std::pair<int, StopID>(coordinate_order,id));
        }
        std::vector<StopID> stops_coord_vector;
        std::multimap<float, StopID>::const_iterator
                map_iterator = stops_coord_map.begin();
        for (;map_iterator != stops_coord_map.end(); map_iterator++)
        {
            stops_coord_vector.push_back(map_iterator->second);
        }
        int last_element_number = stops_coord_vector.size();
        return stops_coord_vector[last_element_number-1];
        }
    else
        {
            return NO_STOP;
        }

}

std::vector<StopID> Datastructures::find_stops(Name const& name)
{
    // Replace this comment and the line below with your implementation
    // return {NO_STOP};
    std::vector<StopID> stops_vector;
    std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
            stops_iterator = stops_map.begin();
    for (;stops_iterator != stops_map.end(); stops_iterator++)
    {
        if (name == stops_iterator->second->name)
        {
            stops_vector.push_back(stops_iterator->first);
        }
    }
    std::sort(stops_vector.begin(),stops_vector.end());
    return stops_vector;
}

bool Datastructures::change_stop_name(StopID id, const Name& newname)
{
    // Replace this comment and the line below with your implementation
    //return false;
    if (find_id_stops(id))
    {
        std::shared_ptr <Stops> stops_pointer = stops_map[id];
        stops_pointer -> name = newname;
        return true;
    }
    else
    {
        return false;
    }
}

bool Datastructures::change_stop_coord(StopID id, Coord newcoord)
{
    // Replace this comment and the line below with your implementation
    // return false;

    if (find_id_stops(id))
    {
        std::shared_ptr <Stops> stops_pointer = stops_map[id];
        stops_pointer -> coord = newcoord;
        return true;
    }
    else
    {
        return false;
    }
}

bool Datastructures::add_region(RegionID id, const Name &name)
{
    // Replace this comment and the line below with your implementation
    // return false;
    if (!find_id_regions(id))           // if the RegionsID has been already added before
    {
        std::shared_ptr<Regions> new_region = std::make_shared<Regions>();

        new_region -> id = id;
        new_region -> name = name;

        regions_map[id] = new_region;
        number_of_regions += 1;

        return true;
    }
    else
    {
        return false;
    }
}

Name Datastructures::get_region_name(RegionID id)
{
    // Replace this comment and the line below with your implementation
    // return NO_NAME;
    if (find_id_regions(id))
        {
            std::shared_ptr<Regions> regions_pointer = regions_map[id];
            return regions_pointer->name;
        }
        else
        {
            return NO_NAME;
        }
}

std::vector<RegionID> Datastructures::all_regions()
{
    // Replace this comment and the line below with your implementation
    // return {NO_REGION};

    RegionID region_that_is_to_be_pushed;
        std::vector<RegionID> regions_vector;
        std::unordered_map<RegionID, std::shared_ptr<Regions>>::const_iterator
                regions_iterator = regions_map.begin();
        for (;regions_iterator != regions_map.end(); regions_iterator++)
        {
            region_that_is_to_be_pushed = regions_iterator->first;
            regions_vector.push_back(region_that_is_to_be_pushed);
        }
        return regions_vector;
}

bool Datastructures::add_stop_to_region(StopID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    // return false;
    std::shared_ptr <Stops> stops_pointer = stops_map[id];
    if (find_id_stops(id) && find_id_regions(parentid) and
            stops_pointer -> parentid != parentid) // if the StopID and RegionID exist
    {
        stops_pointer->parentid = parentid;

        return true;
    }
    else
    {
        return false;
    }
}

bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    // return false;
    std::shared_ptr <Regions> regions_pointer = regions_map[id];
    if (find_id_regions(id) && find_id_regions(parentid) &&
            regions_pointer -> parentid != parentid) // if the RegionID and RegionID exist and
                                                     // RegionID is not subregion of RegionID parentid
    {
        regions_pointer -> parentid = parentid;
        regions_pointer -> is_here_parent=+1;

        std::shared_ptr <Regions> regions_pointer_parentid = regions_map[parentid];
        regions_pointer_parentid  -> childid = id;

        return true;
    }
    else
    {
        return false;
    }
}

std::vector<RegionID> Datastructures::stop_regions(StopID id)
{
    // Replace this comment and the line below with your implementation
    // return {NO_REGION};
    if (find_id_stops(id))
    {
        std::vector<RegionID> regions_vector;
        std::shared_ptr<Stops> stops_pointer = stops_map[id];
        regions_vector.push_back(stops_pointer->parentid);

        RegionID r_id = stops_pointer->parentid;
        std::shared_ptr<Regions> regions_pointer = regions_map[r_id];
        if (find_id_regions(r_id))
        {
            if (regions_pointer->is_here_parent == 0)
                {

            }
            else
            {
                regions_vector.push_back(regions_pointer->parentid);
            }
        }
        RegionID reg_id = regions_pointer->parentid;
        if (find_id_regions(reg_id))
        {
            std::shared_ptr<Regions> regions_pointer = regions_map[reg_id];
            if (regions_pointer-> is_here_parent == 0)
                {

            }
            else
            {
                regions_vector.push_back(regions_pointer->parentid);
            }
        }

        return regions_vector;
    }

    else
    {
        return {NO_REGION};
    }
}

void Datastructures::creation_finished()
{
    // Replace this comment with your implementation
    // You don't have to use this method for anything, if you don't need it
}

std::pair<Coord,Coord> Datastructures::region_bounding_box(RegionID id)
{
    // Replace this comment and the line below with your implementation
    // return {NO_COORD, NO_COORD};
    if (find_id_regions(id))
    {
        std::pair<Coord,Coord> box_coordinates;
        int y_coord = 0;
        int x_coord = 0;
        std::vector<int> xs;
        std::vector<int> ys;

        std::shared_ptr <Regions> regions_pointer_1 = regions_map[id];
        RegionID child_1 = regions_pointer_1 -> childid;
//        std::shared_ptr <Regions> regions_pointer_2 = regions_map[child_1];
//        RegionID child_2 = regions_pointer_2 -> childid;

        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            if (stops_iterator->second->parentid == id)
                {
                x_coord = stops_iterator->second->coord.x;
                xs.push_back(x_coord);

                y_coord = stops_iterator->second->coord.y;
                ys.push_back(y_coord);
                }
            else if (stops_iterator->second->parentid == child_1 and
                     regions_pointer_1 ->childid == child_1)
                {
                x_coord = stops_iterator->second->coord.x;
                xs.push_back(x_coord);
                y_coord = stops_iterator->second->coord.y;
                ys.push_back(y_coord);
                }
//            else if (stops_iterator->second->parentid == child_2 and
//                     regions_pointer_2 ->childid == child_2)
//                {
//                x_coord = stops_iterator->second->coord.x;
//                xs.push_back(x_coord);
//                y_coord = stops_iterator->second->coord.y;
//                ys.push_back(y_coord);
//                }

            else
                continue;
        }

        box_coordinates=bounding_box(xs,ys);
        return box_coordinates;
    }
    else
    {
        return {NO_COORD, NO_COORD};
    }
}


std::vector<StopID> Datastructures::stops_closest_to(StopID id)
{
    // Replace this comment and the line below with your implementation
    // return {NO_STOP};
    if (find_id_stops(id))
    {
        std::multimap<float, StopID> distances_coord_map;
        StopID id_original = id;
        std::unordered_map<StopID, std::shared_ptr<Stops>>::const_iterator
                stops_iterator = stops_map.begin();
        for (;stops_iterator != stops_map.end(); stops_iterator++)
        {
            StopID id = stops_iterator->first;
            int a = stops_iterator->second->coord.x;
            int b = stops_iterator->second->coord.y;

            float distance_order = for_distances_ordering(id_original, a, b);
            distances_coord_map.insert(std::pair<int, StopID>(distance_order,id));
        }

        std::vector<StopID> distances_coord_vector;
        std::multimap<float, StopID>::const_iterator
                map_iterator = distances_coord_map.begin();
        for (;map_iterator != distances_coord_map.end(); map_iterator++)
        {
            distances_coord_vector.push_back(map_iterator->second);
        }
        distances_coord_vector.erase (distances_coord_vector.begin());
        distances_coord_vector.resize(5);
        return distances_coord_vector;

    }
    else
    {
        return {NO_STOP};
    }
}

bool Datastructures::remove_stop(StopID id)
{
    // Replace this comment and the line below with your implementation
    // return false;
    if (find_id_stops(id))
     {
         stops_map.erase(id);
         number_of_stops-=1;
         return true;
     }
     else
     {
         return false;
     }
}


// new one
bool Datastructures::find_id_stops(StopID id)
{
    if (stops_map.find(id) == stops_map.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

// new one
double Datastructures::for_coordinates_ordering(StopID id)
{
    int x = stops_map[id]->coord.x;
    int y = stops_map[id]->coord.y;
    float coordinate_order = 10000* sqrt (x*x + y*y);
    return coordinate_order;
}


double Datastructures::for_distances_ordering(StopID id, int a, int b)
{
    int x = stops_map[id]->coord.x;
    int y = stops_map[id]->coord.y;

    float distance_order = 10000*sqrt( (a-x)*(a-x) + (b-y)*(b-y) );
    return distance_order;
}

bool Datastructures::find_id_regions(RegionID id)
{
    if (regions_map.find(id) == regions_map.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}
std::pair<Coord,Coord> Datastructures::bounding_box(vector<int> xs, vector<int> ys)
{
    std::pair<Coord,Coord> box_coordinates;
    int xmin= *min_element(xs.begin(), xs.end());
    int xmax= *max_element(xs.begin(), xs.end());
    int ymin= *min_element(ys.begin(), ys.end());
    int ymax= *max_element(ys.begin(), ys.end());
    box_coordinates.first  = {xmin,ymin};
    box_coordinates.second = {xmax,ymax};
    return box_coordinates;
}

RegionID Datastructures::stops_common_region(StopID id1, StopID id2)
{
    // Replace this comment and the line below with your implementation
    return NO_REGION;
}

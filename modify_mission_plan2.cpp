/*
Code will clone current mission plan, upload a mission plan and segment a mission plan.
*/

// variable to hold downloaded mission plan

// variable to hold current step in mission plan

// variable to hold new mission plan

// list of waypoint types (Not sure if requiered)
// list_of_waypoint_types = ["normal", "clockwise", "counterclockwise", "drop_package", "glide", "land_no_power",
//                           "automatic_take_off", "waypoint_passive_search", "waypoint_active_search"]

// method to download current mission plan

// method to upload new mission plan (including the starting step)

// method to segment a mission plan. Return a list of waypoints with waypoint types. Unlear how to do currently

// method to check current mission state. Return current waypoint type and distance to next waypoint.
#include <utility>
#include <vector>
#include <stdio.h>
using namespace std;



class mission_plan
{   
                  
    public:
        

        // code to get mission plan from ground station. This is a MAVSDK plan and an array fo strings
        auto get_mission_plan()
        {  
            
            vector<pair<int,int>> initial_mission_plan;  
            int MAVSDK_MISSION_PLAN = 1;
            int ARRAY_OF_STRINGS = 1;
            initial_mission_plan.emplace_back(MAVSDK_MISSION_PLAN,ARRAY_OF_STRINGS);
            
            return initial_mission_plan;
        }

};
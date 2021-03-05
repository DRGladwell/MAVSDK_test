
/*
This is the main loop of the project. From here the code running on the Rasberry Pi2
is controlled. For the most part the code operates as follows.
 1) Determine current mission state of UAV.
 2) If necessary, launch code block that manages that UAV mission state.
 3.1) the code block will usually communicate with the flight controller. If so
    this is achieved through MAVSDK.
 3.2) the code block may communicate to the ground station in some mission states. This
    communication will use MAVlink, but the MAVSDK (which simplifies MAVLink communication)
    might not be able to handle the custom messages.
*/

#include "uav_health.cpp"
#include "modify_mission_plan2.cpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

#define mission_plan_type vector<pair<int, int>> //just for type
#define normal 1

// Main that performs setup and launches main loop
bool mission_terminated = false;
mission_plan_type initial_mission_plan; // NEED MOFIFYING PAIR TYPE IN FUTURE

class UAV_Main
{
public:
                  void statement(int waypoint)
                  {
                                    cout << "we arrived at the end of our journey" << endl;
                  }

                   // loom at mission plan and update state machine.
                  void mission_state_machine(mission_plan_type initial_mission_plan)
                  {

                                    for (auto iter : initial_mission_plan) //PORBABLY INCORRECT STATEMENT
                                    {
                                                      int waypoint = iter.first;
                                                      int category = iter.second;

                                                      switch (category)
                                                      {
                                                      case normal:
                                                                        statement(waypoint);
                                                                        break; //optional
                                                      //       case clockwise :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case counterclockwise :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case drop_package :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case glide :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case land_no_power :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case automatic_take_off :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case waypoint_passive_search :
                                                      //          statement(s);
                                                      //          break; //optional
                                                      //       case waypoint_active_search :
                                                      //          statement(s);
                                                      //          break; //optional

                                                      // you can have any number of case statements.
                                                      default: //Optional
                                                                        statement(waypoint);
                                                      }
                                    }
                  }


                  // Last checks before starting take off
                  void initiate_launch_check(mission_plan mission_p, mission_plan_type initial_mission_plan)
                  {
                                    int restart = 1;
                                    int get_mission_plan_again = 1;

                                    //restart
                                    if (restart != 1)
                                    {
                                                      run_uav();
                                    }
                                    //get again mission plan
                                    else if (get_mission_plan_again != 1)
                                    {
                                                      mission_p.get_mission_plan();
                                    }
                                    //start take off
                                    else
                                    {
                                                      mission_state_machine(initial_mission_plan);
                                    }
                  }

                  // Checks if the uav_health is okay
                  void check_uav_health(UAV_Health uav_health_obj)
                  {
                                    // Continuously check if ground control has started mission
                                    while (true)
                                    {
                                                      // if statment = true providing the ground control wants to start mission
                                                      if (uav_health_obj.UAV_health() == false)
                                                      {
                                                                        run_uav();
                                                      }
                                                      else{
                                                                        break;
                                                      }
                                                      break;
                                    }
                  }

                  // Checks that mission starts properly, to then start the program
                  void check_mission_start()
                  {
                                    // Continuously check if ground control has started mission
                                    while (true)
                                    {
                                                      int i = 1;
                                                      // if statment = true providing the ground control wants to start mission
                                                      if (i == 1)
                                                      {
                                                                        break;
                                                      }
                                    }
                  }

                  void run_uav()
                  {
                                    UAV_Health uav_health_obj;
                                    mission_plan mission_p;

                                    //Check that ground control sends message correctly
                                    check_mission_start();
                                    cout << " here1 " << endl;
                                    //Check UAV is operational
                                    check_uav_health(uav_health_obj);
                                    cout << " here2 " << endl;
                                    initial_mission_plan = mission_p.get_mission_plan();
                                    cout << " here3 " << endl;
                                    initiate_launch_check(mission_p, initial_mission_plan);
                  }
};

int main()
{
                  UAV_Main our_system_launch;
                  our_system_launch.run_uav();
}
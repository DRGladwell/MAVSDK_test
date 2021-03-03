/**
 * @file fly_mission.cpp
 *
 * @brief Demonstrates how to Add & Fly Waypoint missions using the MAVSDK.
 * The example is summarised below:
 * 1. Adds mission items.
 * 2. Starts mission from first mission item.
 * 3. Illustrates Pause/Resume mission item.
 * 4. Exits after the mission is accomplished.
 *
 * @author Julian Oes <julian@oes.ch>,
 *         Shakthi Prashanth M <shakthi.prashanth.m@intel.com>
 * @date 2017-09-06
 */

/*

to use
./test1 udp://:14540


*/

#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/mission/mission.h>
#include <mavsdk/plugins/telemetry/telemetry.h>

#include <functional>
#include <future>
#include <iostream>

#define ERROR_CONSOLE_TEXT "\033[31m" // Turn text on console red
#define TELEMETRY_CONSOLE_TEXT "\033[34m" // Turn text on console blue
#define NORMAL_CONSOLE_TEXT "\033[0m" // Restore normal console colour

using namespace mavsdk;
using namespace std::placeholders; // for `_1`
using namespace std::chrono; // for seconds(), milliseconds()
using namespace std::this_thread; // for sleep_for()

// Handles Action's result
inline void handle_action_err_exit(Action::Result result, const std::string& message);
// Handles Mission's result
inline void handle_mission_err_exit(Mission::Result result, const std::string& message);
// Handles Connection result
inline void handle_connection_err_exit(ConnectionResult result, const std::string& message);


// static Mission::MissionItem  make_mission_item(
//     double latitude_deg,
//     double longitude_deg,
//     float relative_altitude_m,
//     float speed_m_s,
//     bool is_fly_through,
//     float gimbal_pitch_deg,
//     float gimbal_yaw_deg,
//     Mission::MissionItem::CameraAction camera_action);

void usage(std::string bin_name)
{
    std::cout << NORMAL_CONSOLE_TEXT << "Usage : " << bin_name << " <connection_url>" << std::endl
              << "Connection URL format should be :" << std::endl
              << " For TCP : tcp://[server_host][:server_port]" << std::endl
              << " For UDP : udp://[bind_host][:bind_port]" << std::endl
              << " For Serial : serial:///path/to/serial/dev[:baudrate]" << std::endl
              << "For example, to connect to the simulator use URL: udp://:14540" << std::endl;
}

int main(int argc, char** argv)
{
    Mavsdk mavsdk;

    {
        auto prom = std::make_shared<std::promise<void>>();
        auto future_result = prom->get_future();

        std::cout << "Waiting to discover system..." << std::endl;
        mavsdk.subscribe_on_new_system([&mavsdk, prom]() {
            const auto system = mavsdk.systems().at(0);

            if (system->is_connected()) {
                std::cout << "Discovered system" << std::endl;
                prom->set_value();
            } else {
                std::cout << "System timed out" << std::endl;
                std::cout << "Exiting." << std::endl;
                exit(0);
            }
        });

        std::string connection_url;
        ConnectionResult connection_result;

        if (argc == 2) {
            connection_url = argv[1];
            connection_result = mavsdk.add_any_connection(connection_url);
        } else {
            usage(argv[0]);
            return 1;
        }

        if (connection_result != ConnectionResult::Success) {
            std::cout << ERROR_CONSOLE_TEXT << "Connection failed for grabbing mission: " << connection_result
                      << NORMAL_CONSOLE_TEXT << std::endl;
            return 1;
        }

        future_result.get();
    }

    auto system = mavsdk.systems().at(0);
    auto action = Action{system};
    auto mission = Mission{system};
    auto telemetry = Telemetry{system};

    while (!telemetry.health_all_ok()) {
        std::cout << "Waiting for system to be ready" << std::endl;
        sleep_for(seconds(1));
    }

    // // START THE NEW MISSION
    // {
    //     auto prom = std::make_shared<std::promise<Mission::Result>>();
    //     auto future_result = prom->get_future();

    //     const Mission::Result result = future_result.get();
    //     std::cout << "Downloading mission." << '\n';
    //     std::pair<Mission::Result, Mission::MissionPlan> result = mission.download_mission();

    //     std::cout << " help " << std::endl;

    //     if (result.first != Mission::Result::Success) {
    //         std::cout << "Mission download failed (" << result.first << "), exiting." << '\n';
    //         return 1;
    //     }
    //     std::cout << "Mission downloaded (MissionItems: "
    //         << result.second.mission_items.size()
    //         << ")" << '\n';


    // }
    
    auto result = mission.download_mission();
    std::cout << (result.first == Mission::Result::Success);

    // {
    //     std::cout << "Downloading mission." << '\n';
    //     std::cout << " stuff " << std::endl;
    //     std::pair<Mission::Result, Mission::MissionPlan> result = mission.download_mission();
        
    //     std::cout << " help " << std::endl;

        // if (result.first != Mission::Result::Success) {
        //     std::cout << "Mission download failed (" << result.first << "), exiting." << '\n';
        //     return 1;
    //     }

    //     std::cout << "Mission downloaded (MissionItems: "
    //         << result.second.mission_items.size()
    //         << ")" << '\n';
    // }


}



//Mission::download_mission_async(const DownloadMissionCallback callback)

// Mission::MissionItem make_mission_item(
//     double latitude_deg,
//     double longitude_deg,
//     float relative_altitude_m,
//     float speed_m_s,
//     bool is_fly_through,
//     float gimbal_pitch_deg,
//     float gimbal_yaw_deg,
//     Mission::MissionItem::CameraAction camera_action)
// {
//     Mission::MissionItem new_item{};
//     new_item.latitude_deg = latitude_deg;
//     new_item.longitude_deg = longitude_deg;
//     new_item.relative_altitude_m = relative_altitude_m;
//     new_item.speed_m_s = speed_m_s;
//     new_item.is_fly_through = is_fly_through;
//     new_item.gimbal_pitch_deg = gimbal_pitch_deg;
//     new_item.gimbal_yaw_deg = gimbal_yaw_deg;
//     new_item.camera_action = camera_action;
//     return new_item;
// }

inline void handle_action_err_exit(Action::Result result, const std::string& message)
{
    if (result != Action::Result::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}

inline void handle_mission_err_exit(Mission::Result result, const std::string& message)
{
    if (result != Mission::Result::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Handles connection result
inline void handle_connection_err_exit(ConnectionResult result, const std::string& message)
{
    if (result != ConnectionResult::Success) {
        std::cerr << ERROR_CONSOLE_TEXT << message << result << NORMAL_CONSOLE_TEXT << std::endl;
        exit(EXIT_FAILURE);
    }
}
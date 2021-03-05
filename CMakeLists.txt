cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(UAV_MAVSDK_WORKSPACE_CPP)

find_package(Threads REQUIRED)

if(NOT MSVC)
    add_definitions("-Wall -Wextra")
else()
    add_definitions("-WX -W2")
endif()

find_package(MAVSDK REQUIRED)

add_executable(modify_plan
    main.cpp
)

target_link_libraries(modify_plan
    MAVSDK::mavsdk_action
    MAVSDK::mavsdk_mission
    MAVSDK::mavsdk_telemetry
    MAVSDK::mavsdk
    ${CMAKE_THREAD_LIBS_INIT}
)

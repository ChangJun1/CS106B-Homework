cmake_minimum_required(VERSION 3.25)
project(CS106B_Homework)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++20 -Wall")

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
    set(GTEST_ROOT "D:\\3rd_party\\googletest\\install")
ELSE ()
    MESSAGE(STATUS "current platform: ${CMAKE_SYSTEM_NAME}")
ENDIF ()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(OnlyConnect Assignment1/OnlyConnect.cpp)
add_executable(PlayingFair Assignment1/PlayingFair.cpp)

target_link_libraries(OnlyConnect ${GTEST_BOTH_LIBRARIES})
target_link_libraries(PlayingFair ${GTEST_BOTH_LIBRARIES})


target_link_libraries(OnlyConnect ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(PlayingFair ${CMAKE_THREAD_LIBS_INIT})

add_test(OnlyConnectTest OnlyConnect)
add_test(PlayingFairTest PlayingFair)

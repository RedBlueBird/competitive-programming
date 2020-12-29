cmake_minimum_required(VERSION 3.16)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 14)

#USACO unfinished problems
add_executable(1-SwitchingOnTheLights USACO/2015-2016/1-Dec/Silver/1-SwitchingOnTheLights.cpp)

add_executable(2-LoadBalancing USACO/2015-2016/3-Feb/Silver/2-LoadBalancing.cpp)

add_executable(2-SnowBoots USACO/2017-2018/3-Feb/Silver/2-SnowBoots.cpp)
add_executable(3-Teleportation USACO/2017-2018/3-Feb/Silver/3-Teleportation.cpp)

add_executable(1-SleepyCowHerding USACO/2018-2019/3-Feb/Silver/1-SleepyCowHerding.cpp)

add_executable(2-Meetings USACO/2019-2020/1-Dec/Silver/2-Meetings.cpp)
add_executable(3-MilkVisits USACO/2019-2020/1-Dec/Silver/3-MilkVisits.cpp)

add_executable(3-WormholeSort USACO/2019-2020/2-Jan/Silver/3-WormholeSort.cpp)

add_executable(1-SwapitySwapitySwap USACO/2019-2020/3-Feb/Silver/1-SwapitySwapitySwap.cpp)
add_executable(2-Triangles USACO/2019-2020/3-Feb/Silver/2-Triangles.cpp)

#CSES unfinished problems
add_executable(16-GridPaths CSES/1-IntroductoryProblems/16-GridPaths.cpp)

add_executable(17-SumOfThreeValues CSES/2-SortingAndSearching/17-SumOfThreeValues.cpp)
add_executable(26-MovieFestival-II CSES/2-SortingAndSearching/26-MovieFestival-II.cpp)
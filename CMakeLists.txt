cmake_minimum_required(VERSION 3.16)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 14)

#USACO Silver unfinished problems #12
add_executable(2-LoadBalancing USACO/2015-2016/3-Feb/Silver/2-LoadBalancing.cpp)

add_executable(3-Teleportation USACO/2017-2018/3-Feb/Silver/3-Teleportation.cpp)

add_executable(1-SleepyCowHerding USACO/2018-2019/3-Feb/Silver/1-SleepyCowHerding.cpp)

add_executable(2-Meetings USACO/2019-2020/1-Dec/Silver/2-Meetings.cpp)

add_executable(1-SwapitySwapitySwap USACO/2019-2020/3-Feb/Silver/1-SwapitySwapitySwap.cpp)
add_executable(2-Triangles USACO/2019-2020/3-Feb/Silver/2-Triangles.cpp)

add_executable(1-FieldReduction USACO/2015-2016/4-UsOpen/Silver/1-FieldReduction.cpp)

add_executable(2-BovineGenomics USACO/2016-2017/4-UsOpen/Silver/2-BovineGenomics.cpp)
add_executable(3-WheresBessie USACO/2016-2017/4-UsOpen/Silver/3-WheresBessie.cpp)

add_executable(3-MultiplayerMoo USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp)

add_executable(1-LeftOut USACO/2018-2019/4-UsOpen/Silver/1-LeftOut.cpp)
add_executable(2-CowSteepleChase-II USACO/2018-2019/4-UsOpen/Silver/2-CowSteepleChase-II.cpp)

#CSES unfinished problems
add_executable(GridPaths CSES/1-IntroductoryProblems/GridPaths.cpp)

add_executable(JosephusProblem-II CSES/2-SortingAndSearching/JosephusProblem-II.cpp)
add_executable(NestedRangesCheck CSES/2-SortingAndSearching/NestedRangesCheck.cpp)
add_executable(SumOfThreeValues CSES/2-SortingAndSearching/SumOfThreeValues.cpp)
add_executable(SlidingCost CSES/2-SortingAndSearching/SlidingCost.cpp)

add_executable(RoundTrip-II CSES/4-GraphAlgorithms/RoundTrip-II.cpp)
add_executable(PlanetsQueries CSES/4-GraphAlgorithms/PlanetsQueries.cpp)

#USACO Gold unfinished problems
add_executable(1-AngryCows USACO/2015-2016/2-Jan/Gold/1-AngryCows.cpp)

add_executable(1-Moocast USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp)
add_executable(2-CowChecklist USACO/2016-2017/1-Dec/Gold/2-CowChecklist.cpp)

add_executable(3-FencedIn USACO/2015-2016/3-Feb/Gold/3-FencedIn.cpp)

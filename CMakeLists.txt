cmake_minimum_required(VERSION 3.16)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 14)

#USACO Gold unfinished problems
add_executable(HoofPaperScissors USACO/2016-2017/2-Jan/Gold/2-HoofPaperScissors.cpp)

#CSES unfinished problems
add_executable(GridPaths CSES/1-IntroductoryProblems/GridPaths.cpp)

add_executable(SumOfThreeValues CSES/2-SortingAndSearching/SumOfThreeValues.cpp)
add_executable(SlidingMedian CSES/2-SortingAndSearching/SlidingMedian.cpp)
add_executable(MovieFestival-II CSES/2-SortingAndSearching/MovieFestival-II.cpp)
add_executable(NestedRangesCheck CSES/2-SortingAndSearching/NestedRangesCheck.cpp)

add_executable(FlightDiscount CSES/4-GraphAlgorithms/FlightDiscount.cpp)
add_executable(RoundTrip-II CSES/4-GraphAlgorithms/RoundTrip-II.cpp)

#USACO Silver unfinished problems
add_executable(2-LoadBalancing USACO/2015-2016/3-Feb/Silver/2-LoadBalancing.cpp)

add_executable(3-Teleportation USACO/2017-2018/3-Feb/Silver/3-Teleportation.cpp)

add_executable(1-SleepyCowHerding USACO/2018-2019/3-Feb/Silver/1-SleepyCowHerding.cpp)

add_executable(2-Meetings USACO/2019-2020/1-Dec/Silver/2-Meetings.cpp)

add_executable(1-SwapitySwapitySwap USACO/2019-2020/3-Feb/Silver/1-SwapitySwapitySwap.cpp)
add_executable(2-Triangles USACO/2019-2020/3-Feb/Silver/2-Triangles.cpp)

add_executable(1-FieldReduction USACO/2015-2016/4-UsOpen/Silver/1-FieldReduction.cpp)

add_executable(2-BovineGenomics USACO/2016-2017/4-UsOpen/Silver/2-BovineGenomics.cpp)
add_executable(3-WheresBessie USACO/2016-2017/4-UsOpen/Silver/3-WheresBessie.cpp)

add_executable(1-OutOfSorts USACO/2017-2018/4-UsOpen/Silver/1-OutOfSorts.cpp)
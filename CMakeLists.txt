cmake_minimum_required(VERSION 3.16)
project(competitive-programming)

set(CMAKE_CXX_STANDARD 14)

add_executable(debug debug.cpp)
add_executable(test USACO/test.cpp)

#USACO Silver unfinished problems #14
add_executable(2-LoadBalancing USACO/2015-2016/3-Feb/Silver/2-LoadBalancing.cpp)

add_executable(3-Teleportation USACO/2017-2018/3-Feb/Silver/3-Teleportation.cpp)

add_executable(1-SleepyCowHerding USACO/2018-2019/3-Feb/Silver/1-SleepyCowHerding.cpp)

add_executable(2-Meetings USACO/2019-2020/1-Dec/Silver/2-Meetings.cpp)

add_executable(2-Triangles USACO/2019-2020/3-Feb/Silver/2-Triangles.cpp)

add_executable(1-FieldReduction USACO/2015-2016/4-UsOpen/Silver/1-FieldReduction.cpp)

add_executable(2-BovineGenomics USACO/2016-2017/4-UsOpen/Silver/2-BovineGenomics.cpp)
add_executable(3-WheresBessie USACO/2016-2017/4-UsOpen/Silver/3-WheresBessie.cpp)

add_executable(3-MultiplayerMoo USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp)

add_executable(1-LeftOut USACO/2018-2019/4-UsOpen/Silver/1-LeftOut.cpp)
add_executable(2-CowSteepleChase-II USACO/2018-2019/4-UsOpen/Silver/2-CowSteepleChase-II.cpp)

add_executable(1-ComfortableCows USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp)
add_executable(3-JustGreenEnough USACO/2020-2021/3-Feb/Silver/3-JustGreenEnough.cpp)

#USACO Gold unfinished problems
add_executable(1-AngryCows USACO/2015-2016/2-Jan/Gold/1-AngryCows.cpp)

add_executable(2-FavoriateColors USACO/2019-2020/4-UsOpen/Gold/2-FavoriateColors.cpp)

add_executable(3-CountTheCows USACO/2020-2021/3-Feb/Gold/3-CountTheCows.cpp)
add_executable(1-StoneGame USACO/2020-2021/3-Feb/Gold/1-StoneGame.cpp)

add_executable(2-Dishwashing USACO/2018-2019/3-Feb/Gold/2-Dishwashing.cpp)

add_executable(2-MilkVisits USACO/2019-2020/1-Dec/Gold/2-MilkVisits.cpp)

add_executable(2-Portals USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp)
add_executable(3-Permutation USACO/2020-2021/4-UsOpen/Gold/3-Permutation.cpp)

add_executable(3-Springboards USACO/2019-2020/2-Jan/Gold/3-Springboards.cpp)

#USACO Bronze unfinished problems
add_executable(3-LoadBalancing USACO/2015-2016/3-Feb/Bronze/3-LoadBalancing.cpp)

add_executable(2-BullInAChinaShop USACO/2015-2016/4-UsOpen/Bronze/2-BullInAChinaShop.cpp)
add_executable(3-FieldReduction USACO/2015-2016/4-UsOpen/Bronze/3-FieldReduction.cpp)

#CSES unfinished problems
add_executable(GridPaths CSES/1-IntroductoryProblems/GridPaths.cpp)

add_executable(SumOfThreeValues CSES/2-SortingAndSearching/SumOfThreeValues.cpp)

add_executable(RoundTrip-II CSES/4-GraphAlgorithms/RoundTrip-II.cpp)

add_executable(SalaryQueries CSES/5-RangeQueries/SalaryQueries.cpp)
add_executable(IncreasingArrayQueries CSES/5-RangeQueries/IncreasingArrayQueries.cpp)

add_executable(NewFlightRoutes CSES/11-AdditionalProblems/NewFlightRoutes.cpp)

#Teams Code + Proco problems are incomplete

#Codeforces unfinished problems

add_executable(1-PairedUp USACO/2021-2022/1-Dec/Gold/1-PairedUp.cpp)
add_executable(2-HILO USACO/2021-2022/1-Dec/Gold/2-HILO.cpp)
add_executable(Scratch Scratch.cpp)
add_executable(3-BraceletCrossings USACO/2021-2022/1-Dec/Gold/3-BraceletCrossings.cpp)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];

    //More generalized problem of 2-SortingAndSearching | 6-MovieFestival
    //We can scan from left to right sort by ending time with negative upper bound or
    //scan right to left sort by starting time with positive upper bound
    //dp[i,j] represents time i to infinity have a maximum possible reward of j
    //The set time from earliest to latest follow a strictly decreasing reward order
    sort(projects.begin(), projects.end());
    set<pair<int,ll>> dp;
    dp.insert(make_pair(INT_MAX, 0));
    for (int i = n-1; i >= 0; i--){
        auto it = dp.upper_bound(make_pair(projects[i][1],0));
        auto best = dp.upper_bound(make_pair(projects[i][0], 0));
        if (it != best && (it->second - projects[i][2])*-1 <= (best->second)*-1)
            continue;
        dp.insert(make_pair(projects[i][0], it->second - projects[i][2]));
    }

    //Output
    cout << -1*(dp.begin()->second);

    return 0;
}
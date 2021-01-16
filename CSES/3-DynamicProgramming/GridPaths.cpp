#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<vector<bool>> map(n+1, vector<bool>(n+1, true));
    for (int i = 1; i <= n; i++){
        string raw;
        cin >> raw;
        for (int j = 1; j <= n; j++){
            if (raw[j-1] == '*'){
                map[i][j] = false;
            }
        }
    }

    //Walk through the map, combine the total path to the point above and left together
    //The only thing that can stop the walk is the obstacles
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    if (map[1][1]) dp[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!map[i][j]) continue;
            dp[i][j] += (dp[i-1][j] + dp[i][j-1])%int(1e9+7);
        }
    }

    //Output
    cout << dp[n][n];

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> cost(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    //Knapsack the way through all the price combinations to find all the pages affordable
    //The iterate through the bottom dp to find the one that have highest page number
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= k; j++){
            dp[i+1][j] = dp[i][j];
            if (j - cost[i] >= 0){
                dp[i+1][j] = max(dp[i+1][j],dp[i][j-cost[i]] + pages[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++){
        ans = max(ans, dp[n][i]);
    }

    //Output
    cout << ans;

    return 0;
}
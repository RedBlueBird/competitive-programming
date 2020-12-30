#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    //Knapsack problem rather self-explanatory
    //Try all the possible combinations for all coins
    //and only keep the one with lowest coin usage
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if (j - coins[i-1] >= 0 && dp[i][j-coins[i-1]] != INT_MAX){
                dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]]+1);
            }
        }
    }

    //Output
    if (dp[n][k] == INT_MAX){
        cout << -1;
    }else {
        cout << dp[n][k];
    }

    return 0;
}
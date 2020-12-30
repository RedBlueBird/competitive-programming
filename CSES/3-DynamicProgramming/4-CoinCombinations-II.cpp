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

    //Similar to 4-CoinCombinations-I, except the loops are reversed
    //Instead looping k first then n, its n first then k
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if (j - coins[i-1] >= 0 && dp[i][j-coins[i-1]] != 0){
                dp[i][j] = (dp[i][j]+dp[i][j-coins[i-1]])%int(1e9+7);
            }
        }
    }

    //Output
    cout << dp[n][k];

    return 0;
}
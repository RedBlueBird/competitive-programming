#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //If the total sum is odd, then it is impossible to split
    //Otherwise this is same as 4-CoinCombinations-II
    //Goal is to count the total ways to reach sum/4 using knapsack
    //Only using 1 to n-1 for this dp, otherwise it will count subsets twice
    int k = (n+1)*n/2;
    if (k%2){
        cout << 0;
        return 0;
    }
    k /= 2;
    vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j <= k; j++){
            dp[i+1][j] = dp[i][j];
            if (j-i-1 >= 0 && dp[i][j-i-1] != 0){
                dp[i+1][j] = (dp[i+1][j]+dp[i][j-i-1])%ll(1e9+7);
            }
        }
    }

    //Output
    cout << dp[n-1][k];

    return 0;
}
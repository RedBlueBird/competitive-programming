#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //dp[i][j]:
    //  i stands for the i-th element in the nums
    //  j stands for # occurrence of j
    //The dynamic programming can be defined as:
    //  dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
    ll sums = 0;
    vector<vector<ll>> dp(n, vector<ll>(k+2,0));
    for (int i = 0; i < n; i++){
        if (nums[i] != 0){
            if (i == 0) dp[i][nums[i]] = 1;
            else dp[i][nums[i]] = (dp[i-1][nums[i]-1] + dp[i-1][nums[i]] + dp[i-1][nums[i]+1])%ll(1e9+7);
            continue;
        }
        for (int j = 1; j <= k; j++){
            if (i == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%ll(1e9+7);
        }
    }
    for (int i = 1; i <= k; i++){
        sums = (sums+dp[n-1][i])%ll(1e9+7);
    }

    //Output
    cout << sums;

    return 0;
}
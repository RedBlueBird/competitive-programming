#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        dp[i][0] = 1;
    }

    //Self-explanatory 3d dp
    //<comment>
    //Self-explanatory doesn't mean the solution is easy to figure out by yourself
    //It just meant the solution code is easy to read/understand
    //<comment>
    for (int j = 1; j < n; j++){
        for (int i = 0; i + j < n; i++){
            if (nums[i] == nums[i+j]){
                for (int k = 0; k < j; k++){
                    if (nums[i+k] == nums[i]){
                        dp[i][j] = min(dp[i][j], dp[i][k]+dp[i+k+1][j-k-1]-1);
                    }
                }
            }
            for (int k = 0; k < j; k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[i+k+1][j-k-1]);
        }
    }

    //Output
    cout << dp[0][n-1];

    return 0;
}
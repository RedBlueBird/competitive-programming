#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("snakes.out");
    ifstream fin("snakes.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++){
        fin >> nums[i];
    }

    //Construct prefix sum array to get range sum in O(1) time
    //Construct a dp matrix and set all the values in dp[0][0:k+1] to 0
    //dp[i][j] is the minimum total wasted space after i groups of snakes with j changes
    //Intuition is similar to USACO 2018 Dec Gold 3-Teamwork
    vector<int> psum(n+1);
    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    for (int i = 1; i <= n; i++)
        psum[i] = psum[i-1] + nums[i];
    for (int i = 0; i <= k; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++){
        int maxs = nums[i];
        for (int j = i; j >= 1; j--){
            maxs = max(maxs, nums[j]);
            int costs = maxs * (i-j+1) - (psum[i]-psum[j-1]);
            for (int h = 1; h <= k; h++)
                dp[i][h] = min(dp[i][h], dp[j-1][h-1] + costs);
            if (j == 1)
                dp[i][0] = costs;
        }
    }

    //Output
    fout << dp[n][k];

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("taming.out");
    ifstream fin("taming.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++)
        fin >> nums[i];

    //dp[i][j][k] = the minimum changes with k breakouts in the first i days where last breakout happened at j
    //If k is only 1, then j can only be 1, since the first day is guaranteed to occur a breakout
    //If j < i, dp[i][j][k] = dp[i-1][j][k]
    //If j == i, dp[i][j][k] = min(dp[i-1][h][k-1]) for k-1 <= h < i
    //If nums[i] is not i-j, increase the dp by 1 to accommodate this additional change
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
    for (int i = 1; i <= n; i++){
        for (int k = 1; k <= i; k++){
            for (int j = k; j <= i; j++){
                if (k == 1 && j != 1) continue;
                if (j < i) {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
                else {
                    dp[i][j][k] = INT_MAX;
                    for (int h = k - 1; h < i; h++) {
                        if (k-1 == 1 && h != 1) continue;
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][h][k - 1]);
                    }
                }
                if (nums[i] != i-j) {
                    dp[i][j][k]++;
                }
            }
        }
    }

    //Output the minimum for each # of breakouts
    for (int i = 1; i <= n; i++){
        int ans = INT_MAX;
        for (int j = i; j <= n; j++){
            if (i == 1 && j != 1) continue;
            ans = min(ans, dp[n][j][i]);
        }
        fout << ans << "\n";
    }


    return 0;
}


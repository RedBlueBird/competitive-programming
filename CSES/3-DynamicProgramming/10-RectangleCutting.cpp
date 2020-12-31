#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;

    //For each rectangle size ixj
    //It can be cut into two smaller rectangles who's answers has already been computed
    //Unless i = j, it will return 0
    //Otherwise it loop through all the possible rectangles after 1 horz/vert cut and find the minimal one
    //The dp grid is symmetric in a way such that dp[i][j] = dp[j][i]
    if (n > m) swap(n,m);
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0){
                dp[i][j] = j;
                continue;
            }
            if (i == j){
                dp[i][j] = 0;
                continue;
            }
            if (i > j){
                dp[i][j] = dp[j][i];
                continue;
            }
            for (int h = 0; h <= (j-1)/2; h++){
                dp[i][j] = min(dp[i][j], dp[i][h]+dp[i][j-h-1]+1);
            }
            for (int h = 0; h <= (i-1)/2; h++){
                dp[i][j] = min(dp[i][j], dp[h][j]+dp[i-h-1][j]+1);
            }
        }
    }

    //Output
    cout << dp[n-1][m-1];

    return 0;
}
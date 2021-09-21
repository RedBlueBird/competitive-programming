#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n+1, vector<bool>(m+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            bool a;
            cin >> a;
            grid[i][j] = a;
        }
    }

    //Use dynamic programming
    //dp[i][j] represents the amount of paths available to grid[i][j]
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    if (!grid[1][1])
       dp[1][1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (grid[i][j]) continue;
            dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1])%mod;
        }
    }

    //Output
    cout << dp[n][m];

    return 0;
}
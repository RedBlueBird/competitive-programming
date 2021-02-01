#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXS = 1e6;
const int MOD = 1e9+7;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Precalculate all the solutions up to 1e6
    //Output answer while taking inputs
    int n;
    cin >> n;
    vector<vector<ll>> dp(MAXS, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < MAXS; i++){
        dp[i][0] = (dp[i-1][0]*4 + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]*2) % MOD;
    }
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        cout << (dp[a][0]+dp[a][1])%MOD << "\n";
    }

    return 0;
}
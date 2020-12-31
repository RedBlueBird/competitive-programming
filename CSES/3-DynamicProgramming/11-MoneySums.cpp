#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> coins(n);
    int sums = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        sums += coins[i];
    }

    //Similar to 4-CoinCombinations-II, except it just track if it exist or not instead the values
    vector<vector<bool>> dp(n+1, vector<bool>(sums+1,false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= sums; j++){
            dp[i+1][j] = dp[i+1][j] | dp[i][j];
            if (j - coins[i] >= 0 && dp[i][j-coins[i]])
                dp[i+1][j] = true;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sums; i++){
        if (dp[n][i])
            ans.push_back(i);
    }

    //Output
    cout << ans.size() << "\n";
    for (int i: ans)
        cout << i << " ";

    return 0;
}
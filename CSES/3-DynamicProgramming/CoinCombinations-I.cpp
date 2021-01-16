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

    //Same problem as the 1-DiceCombinations
    //Instead 1-6, they are replaced by dynamic valued coinsZ
    vector<int> dp(k+1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < n; j++){
            if (i-coins[j] >= 0){
                dp[i] = (dp[i]+dp[i-coins[j]])%int(1e9+7);
            }
        }
    }

    //Output
    cout << dp[k];

    return 0;
}
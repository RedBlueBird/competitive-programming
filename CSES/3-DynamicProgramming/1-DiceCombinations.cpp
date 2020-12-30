#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Knapsack dp problem
    //Solution for k is the sum of all previous numbers up to k-6
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i-j >= 0){
                dp[i] = (dp[i]+dp[i-j])%int(1e9+7);
            }
        }
    }

    //Output
    cout << dp[n];

    return 0;
}
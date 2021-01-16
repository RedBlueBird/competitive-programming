#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    string first, second;
    cin >> first >> second;

    //Compare all the substrings of the first to the substrings of the second
    //If the i-th letter in the first is same as the j-th letter in the second, total moves stay the same
    //Otherwise the total move at that instance is the minimum moves next to it +1
    int n = first.size(), m = second.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0){
                dp[i][j] = j;
                continue;
            }
            if (j == 0){
                dp[i][j] = i;
                continue;
            }
            if (first[i-1] == second[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
            }
        }
    }

    //Output
    cout << dp[n][m];

    return 0;
}
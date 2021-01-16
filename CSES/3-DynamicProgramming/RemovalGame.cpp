#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> cards(n);
    ll sums = 0;
    for (int i = 0; i < n; i++){
        cin >> cards[i];
        sums += cards[i];
    }

    //Player1 try to maximize the score difference, Player2 minimizes it
    //dp[i][j] is the score difference between p1 and p2 in the sublist length j from ith index
    //When p1 pick a number from either side, the remaining sublist is shorter and already calculated
    //That score become p2's.
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int j = 0; j < n; j++){
        for (int i = 0; i + j < n; i++){
            if (j == 0){
                dp[i][j] = cards[i];
                continue;
            }
            dp[i][j] = max(cards[i+j]-dp[i][j-1], cards[i]-dp[i+1][j-1]);
        }
    }

    //(half of the total sum) + (player1 and player2 difference) is the player1's total score
    cout << (sums-dp[0][n-1])/2+dp[0][n-1];

    return 0;
}
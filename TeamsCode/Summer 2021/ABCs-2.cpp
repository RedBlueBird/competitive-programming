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
    int n, k;
    cin >> n >> k;
    string seq;
    cin >> seq;
    seq.insert(0, "-");

    //We notice that for a valid solution to be generated, the string must have
    //  their letter segments >= k, excluding the last segment
    //Dp[i][j] tells us the best result iif the color is kept as j for i-k+1 to ith turn
    //Best[i][j] tells us the best result if i-k+2 to ith turn is the last segment of the solution
    //Dp[i][j] is constrained to only maximize its value from j colors k turns earlier
    //  or its current color in the previous turn
    //Best[i][j] is constrained to only maximize its value from j colors 1 turn earlier from dp[i][j]
    // or its current color in the previous turn in Best[i][j]
    vector<vector<int>> track(n+1, vector<int>(3, 0));
    vector<vector<int>> delta(n+1, vector<int>(3, 0));
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    vector<vector<int>> best(n+1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++){
        track[i][int(seq[i]-'A')]++;
        int maxs = 0;
        for (int j = 0; j < 3; j++){
            track[i][j] += track[i-1][j];
            maxs = max(track[i][j], maxs);
        }
        for (int j = 0; j < 3; j++){
            delta[i][j] = delta[i-1][j];
            dp[i][j] = dp[i-1][j];
            best[i][j] = best[i-1][j];
            if (track[i][j] == maxs){
                dp[i][j]++;
                best[i][j]++;
                delta[i][j]++;
            }
            if (i >= 2*k){
                for (int p = 0; p < 3; p++){
                    dp[i][j] = max(dp[i][j], delta[i][j] - delta[i-k][j] + dp[i-k][p]);
                }
            }
            if (i > k){
                for (int p = 0; p < 3; p++){
                    best[i][j] = max(best[i][j], delta[i][j] - delta[i-1][j] + dp[i-1][p]);
                }
            }
        }
    }

    //Output the best result from j colors in nth turn in best[i][j]
    int ans = 0;
    for (int i = 0; i < 3; i++){
        ans = max(ans, best[n][i]);
    }
    cout << ans;

    return 0;
}
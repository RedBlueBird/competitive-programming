#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<vector<int>> grass(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grass[i][j];
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    vector<ll> result(101);
    for (int k = 0; k < 101; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grass[i][j] < 200-k)
                    continue;
                dp[i][j] = max(ll(0), dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod + 1;
                result[k] += dp[i][j];
            }
        }
    }
//    ll ans = result[0];
//    for (int i = 1; i < 101; i++){
//        ans = result[i] - ans;
//        cout << result[i] << " ";
//    }
//    cout << "\n";

    //Output
    cout << result[100]-result[99];

    return 0;
}
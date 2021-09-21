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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<int>> grid(n+1, vector<int>(m+1,0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    //Simple dp
    //For i,j in the grid[i][j]
    //Let it be the minimum value of all grid values between 0 - i, 0 - j
    //This can be achieved using the following dp formula
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = min(grid[i][j], min(dp[i][j-1], dp[i-1][j]));
        }
    }

    //Output answer for each query
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        cout << dp[a][b] << "\n";
    }

    return 0;
}
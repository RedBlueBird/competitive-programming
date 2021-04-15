#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //This problem can be converted to finding the least common substring
    //Which can then be solved through dynamic programming
    //dp[i][j] represents one possible longest common substring from a[:i] and b[:j]
    int test = 0;
    cin >> test;
    for (int t = 0; t < test; t++){
        string a,b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        cout << n+m-2*ans << "\n";
    }


    return 0;
}
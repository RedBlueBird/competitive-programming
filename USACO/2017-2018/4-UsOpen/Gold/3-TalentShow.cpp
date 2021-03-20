#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("talent.out");
    ifstream fin("talent.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, w, total;
    fin >> n >> w;
    vector<int> weights(n+1);
    vector<int> talents(n+1);
    for (int i = 1; i <= n; i++){
        fin >> weights[i] >> talents[i];
        total += talents[i];
    }

    //Using knapsack dp to find all different amounts of talents sum reachable
    //And for each amount of talent, keep the minimum amount of weights possible
    //Solution is the highest ratio of those two
    vector<vector<int>> dp(n+1, vector<int>(total+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= total; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= talents[i] && dp[i-1][j-talents[i]] != INT_MAX){
                dp[i][j] = min(dp[i][j], dp[i-1][j-talents[i]]+weights[i]);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i <= total; i++){
        if (dp[n][i] >= w){
            ans = max(ans, double(i)/double(dp[n][i]));
        }
    }

    //Output
    fout << int(1000*ans);

    return 0;
}


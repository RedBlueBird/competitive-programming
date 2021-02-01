#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("time.out");
    ifstream fin("time.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m, c;
    fin >> n >> m >> c;
    vector<int> costs(n+1);
    for (int i = 1; i <= n; i++){
        fin >> costs[i];
    }
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++){
        fin >> edges[i].first >> edges[i].second;
    }

    //Bellford-like + dp
    //The max profit you can earn can only go up to time = 1000 before the quadratic cost dominant the earnings
    //dp[i][j] = the max profit you can earn at time = i, city = j
    //After each time iteration, keep track the best earnings from city 1 as answer and then output it
    vector<vector<int>> dp(1001, vector<int>(n+1, -1));
    dp[0][1] = 0;
    int ans = 0;
    for (int i = 1; i <= 1000; i++){
        for (auto j: edges){
            int a,b;
            tie(a,b) = j;
            if (dp[i-1][a] == -1) continue;
            dp[i][b] = max(dp[i][b], dp[i-1][a]+costs[b]);
        }
        ans = max(ans, dp[i][1] - c * i * i);
    }

    //Output
    fout << ans;

    return 0;
}
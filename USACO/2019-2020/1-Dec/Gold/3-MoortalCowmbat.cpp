#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

int main() {
    ofstream fout("cowmbat.out");
    ifstream fin("cowmbat.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Convert string to a vector of numbers
    int n,m,k;
    fin >> n >> m >> k;
    string presses;
    fin >> presses;
    vector<int> moves(n+1);
    for (int i = 0; i < n; i++){
        moves[i+1] = int(presses[i]-'a');
    }
    vector<vector<ll>> dist(m, vector<ll>(m));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            fin >> dist[i][j];
        }
    }

    //Find the shortest distance from one letter to another using floyd-warshall
    //Construct prefix sum that stores all the days required to switch all letters to a letter
    //dp[i][j] = min(mins[i-k]+psum[i][j]-psum[i-k][j], dp[i-1][j]+dist[i][j]), for j from 0 to 25
    //mins[i] is the minimum days needed to reach a sequence length i satisfying k
    //psum[i][j] represent the total days needed to convert all letters to i-th letter to letter j
    //dp[i][j] is the minimum days needed to reach a sequence length i ending with letter j satisfying k
    for (int k = 0; k < m; k++){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    vector<vector<ll>> count(n+1, vector<ll>(m, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            count[i][j] = count[i-1][j] + dist[moves[i]][j];
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll>(m, INT_MAX));
    vector<ll> mins(n+1,INT_MAX);
    mins[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++){
            dp[i][j] = dp[i-1][j]+dist[moves[i]][j];
            if (i >= k)
                dp[i][j] = min(dp[i][j], mins[i-k]+count[i][j]-count[i-k][j]);
            mins[i] = min(mins[i],dp[i][j]);
        }
    }

    //Output
    fout << mins[n];

    return 0;
}


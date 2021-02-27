#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Self-explanatory tree dfs
void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<vector<ll>>& dp, int node){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, visited, dp, i);
        dp[node][0] = (dp[node][0] * ((dp[i][1] + dp[i][2])%mod))%mod;
        dp[node][1] = (dp[node][1] * ((dp[i][0] + dp[i][2])%mod))%mod;
        dp[node][2] = (dp[node][2] * ((dp[i][0] + dp[i][1])%mod))%mod;
    }
}

int main() {
    ofstream fout("barnpainting.out");
    ifstream fin("barnpainting.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct tree graph
    //Initialize dp
    int n, k;
    fin >> n >> k;
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(3,1));
    for (int i = 0; i < k; i++){
        int a,b;
        fin >> a >> b;
        for (int j = 0; j < 3; j++){
            if (b-1 == j) continue;
            dp[a][j] = 0;
        }
    }

    //Initiate tree dfs
    vector<bool> visited(n+1);
    dfs(graph, visited, dp, 1);

    //Output
    fout << (dp[1][0] + dp[1][1] + dp[1][2])%mod;

    return 0;
}


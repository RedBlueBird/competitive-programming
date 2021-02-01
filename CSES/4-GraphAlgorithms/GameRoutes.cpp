#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Toposort with dfs and construct the sorted nodes array
void dfs(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& toposort, int node){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, visited, toposort, i);
    }
    toposort.push(node);
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    //Topo-dfs sort
    //For each node in the sorted nodes
    //Add the node's own value to all its own children
    vector<bool> visited(n+1);
    stack<int> toposort;
    dfs(graph, visited, toposort, 1);
    vector<int> dp(n+1);
    dp[1] = 1;
    int curr;
    while (!toposort.empty()){
        curr = toposort.top();
        toposort.pop();
        for (int i: graph[curr]){
            dp[i] = (dp[i]+dp[curr])%int(1e9+7);
        }
    }

    //Output
    cout << dp[n];

    return 0;
}
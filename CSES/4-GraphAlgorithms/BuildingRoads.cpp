#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search all the connected node in the graph
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
    visited[node] = true;
    int n = graph[node].size();
    for (int i = 0; i < n; i++){
        if (visited[graph[node][i]]) continue;
        dfs(graph, visited, graph[node][i]);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[b-1].push_back(a-1);
        graph[a-1].push_back(b-1);
    }

    //Search through all the separate connected nodes
    vector<bool> visited(n);
    vector<pair<int,int>> construct;
    int previous = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        dfs(graph, visited, i);
        ans++;
        if (ans > 1){
            construct.push_back(make_pair(previous, i));
            previous = i;
        }
    }

    //Output
    cout << ans-1 << "\n";
    for (pair<int,int> i: construct)
        cout << i.first+1 << " " << i.second+1 << "\n";

    return 0;
}
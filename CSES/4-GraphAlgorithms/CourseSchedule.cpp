#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Performing a topological sort with dfs
void dfs(vector<vector<int>>& graph, vector<int>& toposort, vector<bool>& visited, int node){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, toposort, visited, i);
    }
    toposort.push_back(node);
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

    //Topological sort, then check if the sort is valid
    //If not, return impossible. Otherwise, return the sorted sequence.
    vector<int> toposort;
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        dfs(graph, toposort, visited, i);
    }
    vector<int> check(n+1);
    for (int i = n-1; i >= 0; i--){
        check[toposort[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j: graph[i]){
            if (check[i] < check[j]){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = n-1; i >= 0; i--){
        cout << toposort[i] << " ";
    }

    return 0;
}
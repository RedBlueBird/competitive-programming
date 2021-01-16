#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the graph to find all the cycles while also construct the path
//If there is a cycle length smaller than current one, replace it
void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, int node, int steps, int& ans, int& end){
    visited[node] = steps;
    for (int i: graph[node]){
        if (visited[i]){
            int dist = visited[node]-visited[i];
            if (dist<=1) continue;
            if (dist < ans){
                ans = dist;
                end = node;
            }
            continue;
        }
        path[i] = node;
        dfs(graph, visited, path, i, steps+1, ans, end);
    }
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

    //Dfs all the connected components, and find the cycle with minimum length
    vector<int> visited(n+1, 0);
    vector<int> path(n+1, 0);
    int ans = n;
    int end = 1;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        dfs(graph, visited, path, i, 1, ans, end);
    }

    //If the cycle length is same as the initialized length, return impossible
    //Otherwise backtrack the constructed path
    if (ans == n){
        cout << "IMPOSSIBLE";
    }else{
        ans++;
        cout << ans+1 << "\n";
        int next = end;
        for (int i = 0; i < ans; i++){
            cout << next << " ";
            next = path[next];
        }
        cout << end;
    }

    return 0;
}
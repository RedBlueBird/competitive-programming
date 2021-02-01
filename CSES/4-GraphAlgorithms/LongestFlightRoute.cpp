#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Topological dfs + some dp
//Set the current node to the maximum value + 1 from its child nodes
//while also constructing the longest flight path
int dfs(vector<vector<int>>& graph, vector<int>& path, vector<int>& visited, int node){
    if (node == int(graph.size())-1)
        return 1;
    int depth = 0;
    int child = -1;
    for (int i: graph[node]){
        if (visited[i] == -1) {
            visited[i] = dfs(graph, path, visited, i);
        }
        if (visited[i] > depth){
            depth = visited[i];
            child = i;
        }
    }

    if (depth != 0) {
        path[node] = child;
        return depth + 1;
    }
    return 0;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Put them in a adjacency list graph
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    //Perform a topological dfs sort
    //If the path is not found, return impossible
    //Otherwise, output the path
    vector<int> path(n+1, -1);
    vector<int> visited(n+1, -1);
    int ans = dfs(graph, path, visited, 1);
    if (ans == 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans << "\n1 ";
    int node = 1;
    while (path[node] != -1){
        node = path[node];
        cout << node << " ";
    }

    return 0;
}
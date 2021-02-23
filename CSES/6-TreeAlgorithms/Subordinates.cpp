#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Depth first search the tree, recursively build up the size of each node
void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& sizes, int node){
    visited[node] = true;
    int size = 0;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph,visited,sizes,i);
        size += sizes[i]+1;
    }
    sizes[node] = size;
    return;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct adjacency list
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        graph[a].push_back(i);
    }

    //Execute dfs
    vector<bool> visited(n+1);
    vector<int> sizes(n+1,0);
    dfs(graph, visited, sizes, 1);

    //Output
    for (int i = 1; i <= n; i++)
        cout << sizes[i] << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the furthest node from the start node and their distance
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int depth, int& furthest, int& ans){
    visited[node] = true;
    if (depth > furthest){
        furthest = depth;
        ans = node;
    }
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, visited, i, depth+1, furthest,ans);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct Adjacency list graph
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //It is guaranteed to get the diameter of the tree this way:
    //Pick any node, find the node that is the furthest away from it.
    //Use that node as the starting point, find the node that is furthest away from it.
    //The distance between those 2 nodes will be the diameter
    vector<bool> visited(n+1);
    int dist = 0;
    int start = 1;
    dfs(graph, visited, start, 0, dist, start);
    dist = 0;
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    dfs(graph, visited, start, 0, dist, start);

    //Output
    cout << dist;

    return 0;
}
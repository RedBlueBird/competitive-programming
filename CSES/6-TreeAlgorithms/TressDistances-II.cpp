#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Keep track of the sizes of each node
//While also track the total distance from all nodes to reach the root node
void initialize(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& sizes, int node, ll& dist){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        initialize(graph, visited, sizes, i, dist);
        sizes[node] += sizes[i];
    }
    dist += sizes[node];
}

//Dfs from the root node, compute the total distance for all nodes to reach the current node
void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& sizes, vector<ll>& dists, int node){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dists[i] = dists[node] + sizes[1] - 2*sizes[i];
        dfs(graph, visited, sizes, dists, i);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Construct tree adjacency graph
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Two depth first search using dp
    vector<bool> visited(n+1);
    vector<int> sizes(n+1, 1);
    ll dist = 0;
    initialize(graph, visited, sizes, 1, dist);
    dist -= sizes[1];
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    vector<ll> dists(n+1);
    dists[1] = dist;
    dfs(graph, visited, sizes, dists, 1);

    //Output
    for (int i = 1; i <= n; i++){
        cout << dists[i] << " ";
    }

    return 0;
}
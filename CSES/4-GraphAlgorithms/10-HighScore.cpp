#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
    if (visited[node]) return;
    visited[node] = true;
    for (int i: graph[node]){
        dfs(graph, visited, i);
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_tuple(a,b,c));
        graph[a].push_back(b);
    }

    //Run Bellman-ford through the edge list
    //For the last iteration, if the score can be increased,
    //and the room is in the same connected component as the ending room, return -1
    //Otherwise, return the corresponding calculated score
    vector<ll> dist(n+1,   LONG_LONG_MIN);
    vector<bool> visited(n+1, false);
    dist[1] = 0;
    for (int i = 1; i <= n; i++){
        for (auto j: edges){
            ll a,b,c;
            tie(a,b,c) = j;
            if (dist[a] != LONG_LONG_MIN) {
                if (i == n && dist[a]+c>dist[b]){
                    dfs(graph, visited, a);
                }else {
                    dist[b] = max(dist[b], dist[a] + c);
                }
            }
        }
    }

    //Output
    if (visited[n]){
        cout << -1;
    }else {
        cout << dist[n];
    }

    return 0;
}
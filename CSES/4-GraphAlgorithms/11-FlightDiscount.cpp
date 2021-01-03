#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(vector<vector<ll>>& graph, vector<bool>& verified, int node){
    verified[node] = true;
    for (auto i: graph[node]){
        if (verified[i]) continue;
        dfs(graph, verified, node);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> graph(n+1);
    vector<vector<ll>> backtrack(n+1);
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        backtrack[b].push_back(a);
    }

    //Run Dijkstra over the directed graph
    priority_queue<pair<ll,ll>> construct;
    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<bool> visited(n+1);
    dist[1] = 0;
    construct.push(make_pair(0,1));
    while(!construct.empty()){
        ll a = construct.top().second; construct.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto e: graph[a]){
            ll b,w;
            tie(b,w) = e;
            if (visited[b]) continue;
            if (dist[a] + w < dist[b]){
                dist[b] = dist[a]+w;
                construct.push(make_pair(-dist[b],b));
            }
        }
    }
    vector<bool> verified(n+1);
    dfs(backtrack, verified, n);
    ll ans = LONG_LONG_MAX;
    for (vector<pair<ll,ll>> i: graph){
        for (pair<ll,ll> j: i){

        }
    }

    return 0;
}
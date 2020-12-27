#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth search through the whole tree of farms, greedily calculate the cowid cows
void dfs(vector<vector<ll>>& graph, ll node, ll& ans, vector<bool>& visited){
    visited[node] = true;

    int counts = 1;
    for (ll i = 0; i < graph[node].size(); i++){
        if (visited[graph[node][i]]) continue;
        counts += 1;
        dfs(graph, graph[node][i], ans, visited);
    }
    if (counts != 1)
        ans += (ll)ceil(log2(counts)) + counts - 1;
}

int main() {
    //Take inputs
    ll n;
    cin >> n;
    vector<vector<ll>> graph(n);
    for (ll i = 0; i < n-1; i++){
        ll a,b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    //Call the dfs on the farms
    ll ans = 0;
    vector<bool> visited(n, false);
    dfs(graph, 0, ans, visited);

    //Output
    cout << ans;

    return 0;
}
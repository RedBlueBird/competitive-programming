#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int tickets = 2;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> graph(n+1);
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    //Run Dijkstra over the directed graph for tickets amount of times
    //This is a dp shortest-distance problem
    priority_queue<pair<ll,ll>> construct;
    vector<vector<ll>> dist(n+1, vector<ll>(tickets, LONG_LONG_MAX));
    for (int i = 0; i < tickets; i++) {
        vector<bool> visited(n + 1);
        construct.push(make_pair(0, 1));
        dist[1][i] = 0;
        while (!construct.empty()) {
            ll a = construct.top().second;
            construct.pop();
            if (visited[a]) continue;
            visited[a] = true;
            for (auto e: graph[a]) {
                ll b, w;
                tie(b, w) = e;
                if (visited[b]) continue;
                if (i && dist[a][i-1] + w/2 < dist[b][i]) {
                    dist[b][i] = dist[a][i-1] + w/2;
                    construct.push(make_pair(-dist[b][i], b));
                }
                if (dist[a][i] + w < dist[b][i]) {
                    dist[b][i] = dist[a][i] + w;
                    construct.push(make_pair(-dist[b][i], b));
                }
            }
        }
    }

    //Output
    cout << dist[n][tickets-1];

    return 0;
}
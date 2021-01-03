#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXS = 1e5+1;
vector<pair<ll,ll>> graph[MAXS];
bool visited[MAXS];
ll dist[MAXS];

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    //Run a Dijkstra in directed graph
    for (int i = 0; i < MAXS; i++) dist[i] = LONG_LONG_MAX;
    priority_queue<pair<ll,ll>> q;
    q.push(make_pair(0,1));
    dist[1] = 0;
    while (!q.empty()){
        ll a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto e: graph[a]){
            ll b,w;
            tie(b,w) = e;
            if (visited[b]) continue;
            if (dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                q.push(make_pair(-dist[b], b));
            }
        }
    }

    //Output every distance
    for (int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}
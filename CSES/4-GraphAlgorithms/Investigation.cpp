#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    //Similar to a normal Dijkstra run
    //This time we also implement:
    //      Dp that tracks all the routes
    //      Mins that tracks the min route
    //      Maxs that tracks the max route
    //When a node's dist + child edge weight != child's dist
    //the dp, mins, maxs reset
    vector<bool> visited(n+1);
    priority_queue<pair<ll,ll>> dijkstra;
    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<int> maxs(n+1, INT_MIN);
    vector<int> mins(n+1, INT_MAX);
    vector<int> dp(n+1, 0);
    dist[1] = 0;
    dp[1] = 1;
    maxs[1] = 0;
    mins[1] = 0;
    dijkstra.push(make_pair(0, 1));
    while (dijkstra.size()){
        ll node = dijkstra.top().second;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i: graph[node]){
            ll b,c;
            tie(b,c) = i;
            if (dist[b] >= dist[node] + c){
                if (dist[b] > dist[node] + c){
                    dp[b] = 0;
                    maxs[b] = maxs[node]+1;
                    mins[b] = mins[node]+1;
                }
                dp[b] = (dp[b] + dp[node])%int(1e9+7);
                dist[b] = dist[node] + c;
                maxs[b] = max(maxs[b], maxs[node]+1);
                mins[b] = min(mins[b], mins[node]+1);
                dijkstra.push(make_pair(-dist[b], b));
            }
        }
    }

    //Output
    cout << dist[n] << " " << dp[n] << " " << mins[n] << " " << maxs[n];

    return 0;
}
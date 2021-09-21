#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> dists(n+1);
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1);
    priority_queue<pii> dijkstra;
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        dists[a] = b;
        dijkstra.push(make_pair(-dists[a], a));
    }
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dists[1] = INT_MAX;

    //Use the friendship as the distance, and the people as nodes
    //This can be solved using simple dijkstra shortest path algorithm
    while (dijkstra.size()){
        int node = dijkstra.top().ss;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (int child: graph[node]){
            if (dists[child] < dists[node]/2){
                dists[child] = dists[node]/2;
                dijkstra.push(make_pair(-dists[child], child));
            }
        }
    }
    vector<pii> ans;
    for (int i = 2; i <= n; i++){
        ans.push_back(make_pair(dists[i], i));
    }
    sort(ans.begin(), ans.end());

    //Output
    for (int i = ans.size()-1; i >= 0; i--){
        cout << ans[i].ss << " " << ans[i].ff << "\n";
    }

    return 0;
}
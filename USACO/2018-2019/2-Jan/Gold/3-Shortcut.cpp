#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Count the amount of cows that will pass through the current node
void dfs(vector<vector<int>>& graph, vector<ll>& flow, vector<int>& cows, int node){
    for (int i: graph[node]){
        dfs(graph, flow, cows, i);
        flow[node] += flow[i];
    }
    flow[node] += cows[node];
}

int main() {
    ofstream fout("shortcut.out");
    ifstream fin("shortcut.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct a weighted adjacency graph
    int n, m, t;
    fin >> n >> m >> t;
    vector<int> cows(n+1);
    for (int i = 1; i <= n; i++){
        fin >> cows[i];
    }
    vector<vector<pair<int,ll>>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b,c;
        fin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    //Use dijkstra to find the minimum distance to reach each node
    //While also construct a DAG that takes minimum lexicographical paths
    //For each node, compute the maximum amount of cows that will reach the node
    vector<bool> visited(n+1);
    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<int> path(n+1, 0);
    priority_queue<pair<ll,int>> dijkstra;
    dist[1] = 0;
    dijkstra.push(make_pair(0,1));
    while (dijkstra.size()){
        int node = dijkstra.top().ss;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i: graph[node]){
            int a;
            ll w;
            tie(a,w) = i;
            if (dist[a] >= dist[node]+w){
                if (dist[a] == dist[node]+w){
                    path[a] = min(path[a],node);
                    continue;
                }
                dist[a] = dist[node]+w;
                path[a] = node;
                dijkstra.push(make_pair(-dist[a],a));
            }
        }
    }
    vector<vector<int>> paths(n+1);
    for (int i = 2; i <= n; i++){
        paths[path[i]].push_back(i);
    }
    vector<ll> flow(n+1,0);
    dfs(paths, flow, cows, 1);

    //Output
    //The answer is equal to the difference between the distance of current node and T
    //times the amount of cows that will reach there
    ll ans = 0;
    for (int i = 2; i <= n; i++){
        if (dist[i] > t){
            ans = max(ans, (dist[i]-t)*flow[i]);
        }
    }
    fout << ans;

    return 0;
}


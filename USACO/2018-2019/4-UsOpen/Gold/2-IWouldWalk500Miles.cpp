#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("walk.out");
    ifstream fin("walk.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;

    //Use minimum spanning tree among the nodes to construct a DAG with minimum edges
    //Normal kruskal won't work in this case as it can reach O(n^2 * log(n)) time complexity
    //Prim's algorithm allows dense graph to have O(n^2) time complexity
    //Compute the minimum edge length, sort the edges, the k-th longest edge is the solution
    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<bool> visited(n+1);
    for (int c = 0; c < n; c++){
        int node = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i] && (node == 0 || dist[i] < dist[node]))
                node = i;
        }
        visited[node] = true;
        for (int i = 1; i <= n; i++){
            if (!visited[i])
                dist[i] = min(dist[i], (2019201913*ll(min(i,node))+2019201949*ll(max(i,node)))%ll(2019201997));
        }
    }
    sort(next(dist.begin()), dist.end());

    //Output
    fout << dist[n+1-k];

    return 0;
}


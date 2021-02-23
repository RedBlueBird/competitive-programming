#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Euler tour the tree
//Record the time it took to reach the current node, and the depth of it
void eulerTour(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& tour, vector<int>& depth, vector<int>& time, int node, int layer){
    visited[node] = true;
    tour.push_back(node);
    depth.push_back(layer);
    time[node] = int(tour.size()-1);
    for (int i: graph[node]){
        if (visited[i]) continue;
        eulerTour(graph, visited, tour, depth, time, i, layer+1);
        tour.push_back(node);
        depth.push_back(layer);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct tree graph
    int n,q;
    cin >> n >> q;
    vector<vector<int>> graph(n+1);
    for (int i = 2; i <= n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Euler tour the tree
    //Sparse table to precompute the lowest common ancestor
    vector<int> time(n+1);
    vector<bool> visited(n+1);
    vector<int> tour;
    vector<int> depth;
    eulerTour(graph, visited, tour, depth, time, 1, 1);
    n = 2*n-1;
    vector<int> log(n+1);
    for (int i = 2; i <= n; i++){
        log[i] = log[i/2]+1;
    }
    vector<vector<pii>> sparse(n, vector<pii>(log[n]+1));
    for (int i = 0; i < n; i++){
        sparse[i][0] = make_pair(depth[i],tour[i]);
    }
    for (int j = 1; j <= log[n]; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            if (sparse[i][j-1].ff < sparse[i+(1<<(j-1))][j-1].ff){
                sparse[i][j] = sparse[i][j-1];
            }else{
                sparse[i][j] = sparse[i+(1<<(j-1))][j-1];
            }
        }
    }

    //The distance between two nodes is
    //  (depth of first node) + (depth of second node) - 2 * (depth of their lowest common ancestor)
    for (int i = 0; i < q; i++){
        int a,b,c;
        cin >> a >> b;
        a = time[a];
        b = time[b];
        if (a>b) swap(a,b);
        int k = log[b-a+1];
        if (sparse[a][k].ff < sparse[b - (1<<k) + 1][k].ff){
            c = sparse[a][k].ss;
        }else{
            c = sparse[b - (1<<k) + 1][k].ss;
        }
        cout << depth[a]+depth[b]-2*depth[time[c]] << "\n";
    }

    return 0;
}
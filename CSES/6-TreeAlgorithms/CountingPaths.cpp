#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Euler tour the tree
//Record the time it took to reach the node, and the depth the node it is in
void eulerTour(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& tour, vector<int>& depth, vector<int>& time, vector<int>& parent, int node, int layer){
    visited[node] = true;
    tour.push_back(node);
    depth.push_back(layer);
    time[node] = int(tour.size()-1);
    for (int i: graph[node]){
        if (visited[i]) continue;
        parent[i] = node;
        eulerTour(graph, visited, tour, depth, time, parent, i, layer+1);
        tour.push_back(node);
        depth.push_back(layer);
    }
}

//Reconstruct the tree nodes' values from their difference sum
int sum(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& diff, int node){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        diff[node] += sum(graph, visited, diff, i);
    }
    return diff[node];
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct the tree graph
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
    vector<int> parent(n+1);
    vector<int> tour;
    vector<int> depth;
    eulerTour(graph, visited, tour, depth, time, parent,1, 1);
    int m = 2*n-1;
    vector<int> log(m+1);
    for (int i = 2; i <= m; i++){
        log[i] = log[i/2]+1;
    }
    vector<vector<pii>> sparse(m, vector<pii>(log[m]+1));
    for (int i = 0; i < m; i++){
        sparse[i][0] = make_pair(depth[i],tour[i]);
    }
    for (int j = 1; j <= log[m]; j++){
        for (int i = 0; i + (1 << j) <= m; i++){
            if (sparse[i][j-1].ff < sparse[i+(1<<(j-1))][j-1].ff){
                sparse[i][j] = sparse[i][j-1];
            }else{
                sparse[i][j] = sparse[i+(1<<(j-1))][j-1];
            }
        }
    }

    //Treat the tree nodes as difference sums
    //Similar to difference sum array but in a tree style
    //Does this for each query
    //Then reconstruct the original value each node had through a recursive summing
    vector<int> diff(n+1,0);
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
        diff[tour[a]]++;
        diff[tour[b]]++;
        diff[c]--;
        diff[parent[c]]--;
    }
    fill(visited.begin(),visited.end(), false);
    sum(graph, visited, diff, 1);

    //Output
    for (int i = 1; i <= n; i++){
        cout << diff[i] << " ";
    }

    return 0;
}
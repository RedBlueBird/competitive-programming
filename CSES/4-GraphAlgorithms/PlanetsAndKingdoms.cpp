#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Topological dfs sort the graph
void toposort(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& topo){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    topo.push_back(node);
}

//Perform the Kosaraju's strongly connected components algorithm
void scc(vector<vector<int>>& graph, vector<int>& component, int node, int type){
    component[node] = type;
    for (int i: graph[node]){
        if (component[i]) continue;
        scc(graph, component, i, type);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct two adjacency graph
    //One of them have edges reversed
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> reversed(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        reversed[b].push_back(a);
    }

    //Kosaraju's algorithm
    //Topological sort first, then categorize each node into a component
    vector<bool> visited(n+1);
    vector<int> topo;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    vector<int> component(n+1,0);
    int c = 1;
    for (int i = n-1; i >= 0; i--){
        if (component[topo[i]]) continue;
        scc(reversed, component, topo[i], c++);
    }
    c--;

    //Output
    cout << c << "\n";
    for (int i = 1; i <= n; i++){
        cout << component[i] << " ";
    }

    return 0;
}
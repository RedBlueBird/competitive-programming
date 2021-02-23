#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Topological dfs sort
void toposort(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& topo){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    topo.push_back(node);
}

//Group all the nodes in the current strongly component
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
    //Construct 2 adjacency graphs
    //One of them edges reversed
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

    //Perform Kosaraju's strongly connected components algorithm
    //If there is more than 1 connected component
    //Answer would be no, and print any two nodes from any two strongly connected components
    //Otherwise yes
    vector<bool> visited(n+1);
    vector<int> topo;
    vector<int> component(n+1);
    int c = 1;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    for (int i = n-1; i >= 0; i--){
        if (component[topo[i]]) continue;
        if (c == 2){
            cout << "NO\n";
            cout << topo[i] << " " << topo[n-1];
            return 0;
        }
        scc(reversed, component, topo[i], c++);
    }

    //Output yes
    cout << "YES";

    return 0;
}
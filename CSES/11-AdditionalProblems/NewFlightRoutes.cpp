#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

void toposort(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& topo){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    topo.push_back(node);
}

void scc(vector<vector<int>>& graph, vector<int>& component, int node, int type, vector<pii>& edges){
    component[node] = type;
    for (int i: graph[node]){
        if (component[i]){
            if (component[i] != type)
                edges.push_back(make_pair(component[i],component[node]));
            continue;
        }
        scc(graph, component, i, type, edges);
    }
}


int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
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

    vector<bool> visited(n+1);
    vector<int> topo;
    vector<int> component(n+1,0);
    vector<int> head;
    vector<pii> edges;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        toposort(graph, visited, i, topo);
    }
    for (int i = n-1; i >= 0; i--){
        if (component[topo[i]]) continue;
        head.push_back(topo[i]);
        scc(reversed, component, topo[i], head.size(), edges);
    }
    vector<vector<int>> outdegree(head.size()+1);
    vector<vector<int>> indegree(head.size()+1);
    for (pii i: edges){
        int a,b;
        tie(a,b) = i;
        outdegree[a].push_back(b);
        indegree[b].push_back(a);
    }
    vector<int> starts;
    vector<int> ends;
    for (int i = 1; i <= head.size(); i++){
        if (outdegree[i].size() == 0){
            ends.push_back(head[i-1]);
        }
        if (indegree[i].size() == 0){
            starts.push_back(head[i-1]);
        }
    }

    //Output
    if (head.size() == 1){
        cout << 0;
        return 0;
    }
    vector<pii> ans;
    for (int i = 0; i < starts.size(); i++){
        if (ends[0] == starts[i]) continue;
        ans.push_back(make_pair(ends[0], starts[i]));
    }
    for (int i = 1; i < ends.size(); i++){
        ans.push_back(make_pair(ends[i],ends[0]));
    }
    cout << ans.size() << "\n";
    for (pii i: ans){
        int a,b;
        tie(a,b) = i;
        cout << a << " " << b << "\n";
    }

    return 0;
}
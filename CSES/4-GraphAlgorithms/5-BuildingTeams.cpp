#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Assign the node a value different from their previous node
//If the neighbor nodes share the same value as the current node, bipartite will be impossible
void dfs(vector<vector<int>>& graph, vector<int>& states, int node, int prev, bool& impossible){
    if (impossible) return;
    if (states[node]) return;
    states[node] = prev%2 + 1;

    for (int i: graph[node]){
        if (states[i] == states[node]){
            impossible = true;
            break;
        }
        dfs(graph, states, i, states[node], impossible);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Dfs all the connected nodes
    vector<int> states(n, 0);
    bool impossible = false;
    for (int i = 0; i < n; i++){
        if (states[i] != 0) continue;
        if (impossible) break;
        dfs(graph, states, i, 1, impossible);
    }

    //Output
    if (impossible){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i: states)
        cout << i << " ";

    return 0;
}
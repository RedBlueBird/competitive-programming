#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the tree
//Assign each node a value starting from 1, only restriction is the current node and its parent
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int type, int parent, int& ans){
    visited[node] = true;

    int c = 0;
    for (int i = 0; i < graph[node].size(); i++){
        if (visited[graph[node][i]]) continue;
        c++;
        while (c == type || c == parent){
            c++;
        }
        ans = max(ans, c);
        dfs(graph, visited, graph[node][i], c, type, ans);
    }
}

int main() {
    ofstream fout("planting.out");
    ifstream fin("planting.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    //Execute the dfs function
    vector<bool> visited(n);
    int ans = 0;
    dfs(graph, visited, 0, 1, 1, ans);

    //Output
    fout << ans;

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& reject, int node){
    if (visited[node]) return;
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i] || reject[i]) continue;
        dfs(graph, visited, reject, i);
    }
}

int main() {
    ofstream fout("closing.out");
    ifstream fin("closing.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Scan the graph every new deletion. Check for the existence of multiple connected component
    vector<bool> reject(n+1);
    for (int i = 0; i < n; i++){
        int a = 0, c = 0;
        if (i) fin >> a;
        reject[a] = true;
        vector<bool> visited(n+1);
        for (int j = 1; j <= n; j++){
            if (visited[j] || reject[j]){
                if (j == n){
                    fout << "YES\n";
                }
                continue;
            }
            if (c++){
                fout << "NO\n";
                break;
            }
            dfs(graph, visited, reject, j);
        }
    }

    return 0;
}
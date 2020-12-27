#include <bits/stdc++.h>
#define ll long long

using namespace std;

//Search for all videos that have not been visited with simple dfs
void dfs(vector<pair<int,int>> graph[], vector<bool>& visited, int node, int limit, int& ans){
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++){
        if (visited[graph[node][i].first] == false && graph[node][i].second >= limit){
            ans++;
            dfs(graph, visited, graph[node][i].first, limit, ans);
        }
    }
}

int main() {
    ofstream fout("mootube.out");
    ifstream fin("mootube.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take Inputs
    int n, m;
    fin >> n >> m;
    vector<pair<int,int>> graph[n];
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        fin >> a >> b >> c;
        graph[a-1].push_back(make_pair(b-1,c));
        graph[b-1].push_back(make_pair(a-1, c));
    }

    //Dfs to search all videos with minimum relevance, output the ans along the way.
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        int ans = 0;
        vector<bool> visited(n, false);
        dfs(graph, visited, b-1, a, ans);
        fout << ans << "\n";
    }

    return 0;
}
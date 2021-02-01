#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search every connected component and mark their boundary
void dfs(vector<vector<int>>& graph, vector<pair<int,int>>& cows, vector<bool>& visited, int node, pair<int,int>& up, pair<int,int>& down){
    visited[node] = true;
    for (int i: graph[node]){
        if (visited[i]) continue;
        up.first = max(up.first, cows[i].first);
        up.second = max(up.second, cows[i].second);
        down.first = min(down.first, cows[i].first);
        down.second = min(down.second, cows[i].second);
        dfs(graph, cows, visited, i, up, down);
    }
}

int main() {
    ofstream fout("fenceplan.out");
    ifstream fin("fenceplan.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<pair<int,int>> cows(n+1);
    vector<vector<int>> graph(n+1);
    for (int i = 1; i <= n; i++){
        fin >> cows[i].first >> cows[i].second;
    }
    for (int i = 1; i <= m; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Iterate through all the connected cows and find the minimum perimeter for each connected component
    int ans = INT_MAX;
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        pair<int,int> up = cows[i];
        pair<int,int> down = cows[i];
        dfs(graph, cows, visited, i, up, down);
        ans = min(ans, (up.first-down.first)*2 + (up.second-down.second)*2);
    }

    //Output
    fout << ans;

    return 0;
}
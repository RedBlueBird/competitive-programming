#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ofstream fout("atlarge.out");
    ifstream fin("atlarge.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(n+1, INT_MAX);
    queue<int> bfs;
    for (int i = 1; i <= n; i++){
        if (graph[i].size() == 1){
            bfs.push(i);
            dist[i] = 0;
        }
    }
    while (!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        for (auto i: graph[node]){
            if (dist[node]+1 < dist[i]){
                dist[i] = dist[node]+1;
                bfs.push(i);
            }
        }
    }
    if (dist[k] == 0){
        fout << 1;
        return 0;
    }
    dist[k] = 0;
    int ans = 0;
    vector<bool> visited(n+1);
    bfs.push(k);
    while (!bfs.empty()){
        int node = bfs.front(); bfs.pop();
        visited[node] = true;
        for (auto i: graph[node]){
            if (dist[node]+1 < dist[i]){
                dist[i] = dist[node]+1;
                bfs.push(i);
            }else{
                if (visited[i])continue;
                visited[i] = true;
                ans++;
            }
        }
    }

    //Output
    fout << ans;

    return 0;
}
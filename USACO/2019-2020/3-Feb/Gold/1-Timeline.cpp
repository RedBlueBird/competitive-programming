#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//<My comment>
//The input value m is kinda useless ngl
//</My comment>

//Topo-dfs sort, construct a topologically sorted array from this function
void dfs(vector<vector<pair<int,int>>>& graph, vector<bool>& visited, vector<int>& toposort, int node){
    visited[node] = true;
    for (auto i: graph[node]){
        int a,b;
        tie(a,b) = i;
        if (visited[a]) continue;
        dfs(graph, visited, toposort, a);
    }
    toposort.push_back(node);
}


int main() {
    ofstream fout("timeline.out");
    ifstream fin("timeline.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct an array that track all the start time
    //Construct an adjacency list graph
    int n, m, c;
    fin >> n >> m >> c;
    vector<int> start(n+1);
    for (int i = 1; i <= n; i++){
        fin >> start[i];
    }
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < c; i++){
        int a,b,c;
        fin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    //Toposort the milking sessions
    //Start from the earliest milking session,
    //greedily set all its children's time to be at least itself's time + edge weight
    vector<bool> visited(n+1);
    vector<int> toposort;
    for (int i = 1; i <= n; i++){
        if (visited[i]) continue;
        dfs(graph, visited, toposort, i);
    }
    for (int i = n-1; i >= 0; i--){
        for (auto j: graph[toposort[i]]){
            int a,b;
            tie(a,b) = j;
            start[a] = max(start[a], start[toposort[i]] + b);
        }
    }

    //Output
    for (int i = 1; i <= n; i++){
        fout << start[i] << "\n";
    }

    return 0;
}
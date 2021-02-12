#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

int main() {
    ofstream fout("dining.out");
    ifstream fin("dining.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct adjacency graph
    //Construct array that stores the best yum for each node
    int n, m, k;
    fin >> n >> m >> k;
    vector<vector<pii>> graph(n+1);
    vector<int> yum(n+1);
    for (int i = 0; i < m; i++){
        int a,b,c;
        fin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    for (int i = 0; i < k; i++){
        int a,b;
        fin >> a >> b;
        yum[a] = max(yum[a], b);
    }

    //Find the shortest distance between each node to barn n using dijkstra
    //Remove all edges connected to barn n
    //Pasture that have hays then construct an edge direct to the barn, cost would be distance - yum
    //If the yum in that pasture is double of the dist, every cow automatically set to true
    //Otherwise find the shortest distance again such that each cow need to eat at least once
    //If the new distance is <= the original, that cow would be true
    vector<bool> visited(n+1);
    vector<int> fdist(n+1, INT_MAX);
    fdist[n] = 0;
    priority_queue<pii> dijkstra;
    dijkstra.push(make_pair(0, n));
    while (dijkstra.size()){
        int node = dijkstra.top().ss;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i: graph[node]){
            int b, w;
            tie(b,w) = i;
            if (fdist[b] > fdist[node]+w){
                fdist[b] = fdist[node]+w;
                dijkstra.push(make_pair(-fdist[b], b));
            }
        }
    }
    vector<pii> dummy;
    swap(graph[n],dummy);
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        if (yum[i]){
            if ((fdist[i])*2 <= yum[i]){
                for (int j = 1; j < n; j++){
                    fout << 1 << "\n";
                }
                return 0;
            }
            graph[i].push_back(make_pair(n,fdist[i]-yum[i]));
            graph[n].push_back(make_pair(i,fdist[i]-yum[i]));
        }
    }
    vector<int> sdist(n+1, INT_MAX);
    sdist[n] = 0;
    dijkstra.push(make_pair(0, n));
    while (dijkstra.size()){
        int node = dijkstra.top().ss;
        dijkstra.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto i: graph[node]){
            int b, w;
            tie(b,w) = i;
            if (sdist[b] > sdist[node]+w){
                sdist[b] = sdist[node]+w;
                dijkstra.push(make_pair(-sdist[b], b));
            }
        }
    }

    //Output true if the new distance is <= the original
    for (int i = 1; i < n; i++){
        if (fdist[i] < sdist[i]){
            fout << 0 << "\n";
        }else{
            fout << 1 << "\n";
        }
    }

    return 0;
}


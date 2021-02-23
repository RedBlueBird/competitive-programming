#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int find(vector<int>& top, int k){
    return k == top[k] ? k : top[k] = find(top, top[k]);
}

bool merge(vector<int>& top, vector<int>& sizes, int a, int b){
    a = find(top, a);
    b = find(top, b);
    if (a == b) return false;
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    top[b] = a;
    return true;
}

int main() {
    ofstream fout("fcolor.out");
    ifstream fin("fcolor.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        graph[b].push_back(a);
    }

    vector<int> sizes(n+1,1);
    vector<int> top(n+1);
    for (int i = 0; i <= n; i++) {
        top[i] = i;
    }
    queue<int> bfs;
    for (int i = 1; i <= n; i++){
        if (graph[i].size()>1)
            bfs.push(i);
    }
    while (bfs.size()) {
        int node = bfs.front();
        bfs.pop();
        int root = find(top, node);
        for (int i = 1; i < graph[node].size(); i++) {
            if (merge(top, sizes, graph[node][0], graph[node][i])) {
                graph[graph[node][0]].insert(end(graph[graph[node][0]]), begin(graph[graph[node][i]]), end(graph[graph[node][i]]));
                graph[graph[node][i]].clear();
            }
        }
        if (graph[graph[node][0]].size()>1)
            bfs.push(graph[node][0]);
    }
    map<int,int> colors;
    int c = 1;
    for (int i = 1; i <= n; i++){
        if (!colors.count(top[i]))
            colors[top[i]] = c++;
    }

    //Output
    for (int i = 1; i <= n; i++){
        fout << colors[top[i]] << "\n";
    }

    return 0;
}


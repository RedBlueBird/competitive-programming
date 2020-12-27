#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Bi-color the graph with depth first search
//If there are any coloring conflict, the whole graph will be marked as impossible
void dfs(vector<vector<pair<int,int>>>& graph, vector<int>& states, int node, bool color, bool& impossible){
    if (impossible) return;
    if (states[node] != 2 && states[node] != color){
        impossible = true;
        return;
    }
    if (states[node] == color) return;
    states[node] = color;

    for (int i = 0; i < graph[node].size(); i++){
        if (graph[node][i].second == 1)
            dfs(graph, states, graph[node][i].first, color, impossible);
        else
            dfs(graph, states, graph[node][i].first, !color, impossible);
    }
}

int main() {
    ofstream fout("revegetate.out");
    ifstream fin("revegetate.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<vector<pair<int,int>>> graph(n);
    for (int i = 0; i < m; i++){
        char a;
        int b,c;
        fin >> a >> b >> c;
        b--;c--;
        if (a == 'S'){
            graph[b].push_back(make_pair(c,1));
            graph[c].push_back(make_pair(b, 1));
        }
        else{
            graph[b].push_back(make_pair(c, 2));
            graph[c].push_back(make_pair(b, 2));
        }
    }

    //For every connected components, the answer will double
    //If impossible coloring is discovered, break and return 0
    vector<int> states(n, 2);
    int ans = 0;
    bool impossible = false;
    for (int i = 0; i < n; i++){
        if (states[i] != 2) continue;
        ans++;
        dfs(graph, states, i, false, impossible);
        if (impossible) break;
    }

    //Output the answer in binary
    if (impossible){
        fout << 0;
    }
    else{
        fout << 1;
        for (int i = 0; i < ans; i++){
            fout << 0;
        }
    }

    return 0;
}
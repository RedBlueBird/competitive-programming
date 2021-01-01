#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXS = 1e6+1;
int n, m, visited[MAXS];
vector<int> graph[MAXS];
string type;
char types[MAXS];

//Depth first search the tree graph
//If the neighbor nodes share the same value, they will belong to the same connected component
void dfs(int node, int count) {
    visited[node] = count;
    for (int i: graph[node]){
        if (visited[i]) continue;
        if (types[i] != types[node]) continue;
        dfs(i, count);
    }
}

int main() {
    ofstream fout("milkvisits.out");
    ifstream fin("milkvisits.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    fin >> n >> m;
    fin >> type;
    for (int i = 0; i < n; i++){
        types[i] = type[i];
    }
    for (int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    //Put all the nodes into a connected component
    int count = 1;
    for (int i = 0; i < n; i++){
        if (visited[i]) continue;
        dfs(i, count);
        count++;
    }

    //If a path took place in 2 different components, then the target value must be seen
    //If only 1 component took place, if that component shares the same target value, it will also be true
    for (int i = 0; i < m; i++){
        int a,b;
        char c;
        fin >> a >> b >> c;
        if (types[a-1] == c || visited[a-1] != visited[b-1]){
            fout << 1;
        }else{
            fout << 0;
        }
    }

    return 0;
}
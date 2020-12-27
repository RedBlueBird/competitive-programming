#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Recursively traverse the tree graph
//Set all the clocks to 12 from bottom up
void recurse(vector<vector<int>>& graph, vector<int>& values, vector<bool>& visited, int node){
    visited[node] = true;

    int sum = 0;
    for (int i = 0; i < graph[node].size(); i++){
        if (visited[graph[node][i]]) continue;
        recurse(graph, values, visited, graph[node][i]);
        sum += values[graph[node][i]];
    }
    values[node] = ((12 + values[node])-(sum%12))%12;
}

int main() {
    ofstream fout("clocktree.out");
    ifstream fin("clocktree.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> values(n);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        values[i] = 12-a;
    }
    for (int i = 0; i < n-1; i++){
        int a,b;
        fin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Traverse the whole graph n times
    //Each time use a different node as the tree's root
    //It will only be possible to start at k-th node
    //if the final value of k-th node is 0 or 11
    int ans = 0;
    for (int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        vector<int> newVals = values;
        recurse(graph, newVals, visited, i);
        if (newVals[i] == 0 || newVals[i] == 11) ans++;
    }

    //Output
    fout << ans;

    return 0;
}
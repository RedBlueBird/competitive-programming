#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Topo-dfs sort, sort the graph based on edges that are no greater than the given threshold
void toposort(vector<vector<pair<int,int>>>& graph, vector<bool>& visited, vector<int>& sorted, int node, int thres){
    visited[node] = true;
    for (pair<int,int> i: graph[node]){
        int a,b;
        tie(a,b) = i;
        if (b > thres) continue;
        if (visited[a]) continue;
        toposort(graph, visited, sorted, a, thres);
    }
    sorted.push_back(node);
}

//Evaluator function for binary search
//Calls the topo-dfs sort with a given threshold and check if there exists a cycle or not
//False if there is, else wise true
bool bisearch(vector<vector<pair<int,int>>>& graph, int thres){
    vector<int> sorted = {0};
    vector<bool> visited(graph.size());
    vector<int> pos(graph.size());
    for (int i = 1; i < graph.size(); i++) {
        if (visited[i]) continue;
        toposort(graph, visited, sorted, i, thres);
    }
    for (int i = 1; i < graph.size(); i++){
        pos[sorted[i]] = i;
    }
    for (int i = 1; i < graph.size(); i++){
        for (pair<int,int> j: graph[i]){
            int a,b;
            tie(a,b) = j;
            if (b > thres) continue;
            if (pos[a] > pos[i]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ofstream fout("milkorder.out");
    ifstream fin("milkorder.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct a graph by creating edges between every two cows in the same line
    //Set each edge's weight property to the j-th line they show up to help the follow up bisearch
    int n, m;
    fin >> n >> m;
    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 1; i <= m; i++){
        int k, a,b;
        fin >> k;
        for (int j = 0; j < k; j++){
            fin >> a;
            swap(a,b);
            if (j) {
                graph[a].push_back(make_pair(b, i));
            }
        }
    }

    //Call the bisearch and determine the value X
    //Count all the indegrees of every node
    //Initiate a modified Kahn algorithm (Lexicographical topo-bfs sort) using priority queue
    //Construct the answer after the sort
    int lo = 1, hi = m;
    while ((hi-lo)>1){
        if (bisearch(graph, (lo+hi)/2)){
            lo += (hi-lo)/2;
        }else{
            hi -= (hi-lo)/2;
        }
    }
    if (!bisearch(graph, lo)) lo = hi;
    vector<int> ans;
    priority_queue<int> kahn;
    vector<bool> visited(n+1);
    vector<int> indegrees(n+1);
    for (int i = 1; i <= n; i++){
        for (pair<int,int> j: graph[i]){
            int a,b;
            tie(a,b) = j;
            if (b > lo) continue;
            indegrees[a]++;
        }
    }
    for (int i = 1; i <= n; i++){
        if (indegrees[i] == 0){
            kahn.push(-1*i);
        }
    }
    while (kahn.size()){
        int node = -1*kahn.top();
        kahn.pop();
        if (visited[node]) continue;
        visited[node] = true;
        ans.push_back(node);
        for (pair<int,int> i: graph[node]){
            int a,b;
            tie(a,b) = i;
            if (b > lo) continue;
            indegrees[a]--;
            if (indegrees[a] == 0){
                kahn.push(-1*a);
            }
        }
    }

    //Output
    for (int i = 0; i < n; i++){
        fout << ans[i];
        if (i < n-1){
            fout << " ";
        }
    }

    return 0;
}
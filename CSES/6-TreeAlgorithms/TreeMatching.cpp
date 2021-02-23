#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Dynamic programming applied on depth-first-search tree
//Each node can each be chosen for an edge or not
//Always keep the best one as it dfs
pii dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
    visited[node] = true;
    int notChosen = 0;
    int chosen = 0;
    for (int i: graph[node]){
        if (visited[i]) continue;
        int a,b;
        tie(a,b) = dfs(graph, visited, i);
        notChosen += b;
        chosen = max(chosen, a+1-b);
    }
    chosen += notChosen;
    return make_pair(notChosen, chosen);
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct adjacency graph
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Execute the dp dfs
    vector<bool> visited(n+1);
    int a,b;
    tie(a,b) = dfs(graph, visited, 1);

    //Output
    cout << max(a,b);

    return 0;
}
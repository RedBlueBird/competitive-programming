#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Breath first search the graph and check for the shortest path to the goal
    //While also constructing the such valid path
    queue<int> bfs;
    vector<int> path(n+1, 0);
    path[1] = -1;
    bfs.push(1);
    while (!bfs.empty()){
        int node;
        node = bfs.front(); bfs.pop();
        if (node == n)
            break;
        for (int i: graph[node]){
            if (path[i] != 0) continue;
            path[i] = node;
            bfs.push(i);
        }
    }

    //If the goal is not reached, return impossible
    //Otherwise collect the nodes that made up the shortest path and output it
    if (path[n]){
        stack<int> ans;
        int node = n;
        while (path[node] != -1){
            ans.push(node);
            node = path[node];
        }
        cout << ans.size()+1 << "\n" << 1;
        while (!ans.empty()){
            cout << " " << ans.top();
            ans.pop();
        }
    }else{
        cout << "IMPOSSIBLE";
    }

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(vector<vector<int>> graph, int node, vector<bool>& visited, int& len){
    visited[node] = true;
    len++;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, i, visited, len);
    }
}

int main() {
    ofstream fout("moocast.out");
    ifstream fin("moocast.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<vector<int>> cows(n);
    for (int i = 0; i < n; i++){
        int a,b,c;
        fin >>a>>b>>c;
        cows[i] = vector<int>{a,b,c};
    }

    vector<vector<int>> graph(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            double dists = sqrt(pow(abs(cows[i][0]-cows[j][0]),2) + pow(abs(cows[i][1]-cows[j][1]),2));
            if (dists <= cows[i][2]) graph[i].push_back(j);
            if (dists <= cows[j][2]) graph[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        int len = 0;
        dfs(graph, i, visited, len);
        ans = max(ans, len);
    }

    //Output
    fout << ans;

    return 0;
}

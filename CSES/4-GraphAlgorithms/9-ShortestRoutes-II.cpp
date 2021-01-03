#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> graph(n+1, vector<ll>(n+1, 1e15));
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        c = min(c, graph[a][b]);
        graph[a][b] = c;
        graph[b][a] = c;
    }

    //Run a Floyd-Warshall 
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    for (int h = 1; h <= n; h++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][h]+graph[h][j]);

    //Output the calculated distance for each query
    for (int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        if (graph[a][b] == 1e15)
            cout << -1 << "\n";
        else
            cout << graph[a][b] << "\n";
    }

    return 0;
}
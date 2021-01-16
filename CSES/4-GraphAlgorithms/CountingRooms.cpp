#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the map for connecting rooms
void dfs(vector<vector<bool>>& map, vector<vector<bool>>& visited, int x, int y){
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size()) return;
    if (visited[x][y]) return;
    if (map[x][y]) return;
    visited[x][y] = true;

    dfs(map, visited, x -1, y );
    dfs(map, visited, x +1, y );
    dfs(map, visited, x , y -1);
    dfs(map, visited, x , y +1);
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(m,true));
    for (int i = 0; i < n; i++){
        string raw;
        cin >> raw;
        for (int j = 0; j < m; j++){
            if (raw[j] == '.')
                map[i][j] = false;
        }
    }

    //Scan through all the unseen rooms, if visited, skip
    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (visited[i][j]) continue;
            if (map[i][j]) continue;
            dfs(map, visited, i, j);
            ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
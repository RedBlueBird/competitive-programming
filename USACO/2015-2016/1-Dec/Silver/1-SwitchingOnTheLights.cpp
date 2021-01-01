#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int Dx[4] = {-1,1,0,0};
int Dy[4] = {0,0,-1,1};

//Depth first search flood fill all the lighted but unvisited rooms
//If a new room is illuminated, check if that room have visited rooms adjacent to it.
//If so, that new room is also visited.
void dfs(vector<vector<vector<pair<int,int>>>>& change, vector<vector<bool>>& lighted, vector<vector<bool>>& visited, int x, int y, int& ans){
    if (x < 0 || x >= change.size() || y < 0 || y >= change.size()) return;
    if (!lighted[x][y] || visited[x][y]) return;
    visited[x][y] = true;

    if (change[x][y].size()){
        for (pair<int,int> p: change[x][y]){
            if (lighted[p.first][p.second]) continue;
            lighted[p.first][p.second] = true;
            ans++;
            for (int i = 0; i < 4; i++){
                int dx = Dx[i]+p.first, dy = Dy[i]+p.second;
                if (dx < 0 || dx >= change.size() || dy < 0 || dy >= change.size()) continue;
                if (visited[dx][dy])
                    dfs(change, lighted, visited, p.first, p.second, ans);
            }
        }
    }
    for (int i = 0; i < 4; i++){
        dfs(change, lighted, visited, x + Dx[i], y + Dy[i], ans);
    }
}

int main() {
    ofstream fout("lightson.out");
    ifstream fin("lightson.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<vector<vector<pair<int,int>>>> change(n, vector<vector<pair<int,int>>>(n));
    for (int i = 0; i < m; i++){
        int a,b,c,d;
        fin >>a>>b>>c>>d;
        a--;b--;c--;d--;
        change[a][b].push_back(make_pair(c,d));
    }

    //Track the rooms that are visited, and the ones that are lighted
    //Initiate the dfs floodfill
    vector<vector<bool>> lighted(n, vector<bool>(n, false));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    lighted[0][0] = true;
    int ans = 1;
    dfs(change, lighted, visited, 0,0, ans);

//    Output
    fout << ans;

    return 0;
}
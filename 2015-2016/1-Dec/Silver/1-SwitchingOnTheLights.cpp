#include <bits/stdc++.h>
#define ll long long

using namespace std;

//Assign lit to all the connected rooms, also activate their corresponding room activation
void dfs(vector<vector<int>>& grid, int x, int y, int& ans, vector<pair<int,int>> connections[], vector<pair<int,int>>& que){
    if (x < 0 || y < 0 || x == grid.size() || y == grid.size()) return;
    if (grid[y][x] == 2 || grid[y][x] == 0) return;
    grid[y][x] = 2;
    ans++;
    for (pair<int,int> i: connections[y*grid.size()+x]){
        if (grid[i.second][i.first] == 0){
            grid[i.second][i.first] = 1;
            que.push_back(i);
        }
    }

    dfs(grid, x-1, y, ans, connections, que);
    dfs(grid, x+1, y, ans, connections, que);
    dfs(grid, x, y-1, ans, connections, que);
    dfs(grid, x, y+1, ans, connections, que);
}

//Check if the rooms are connected
int detect(vector<vector<int>> grid, int x, int y, vector<vector<bool>>& visited){
    if (x < 0 || y < 0 || x == grid.size() || y == grid.size()) return 0;
    if (grid[y][x] == 2) return 1;
    if (grid[y][x] == 0) return 0;
    if (visited[y][x]) return 0;
    visited[y][x] = true;

    int result = 0;
    result |= detect(grid, x-1, y, visited);
    result |= detect(grid, x+1, y, visited);
    result |= detect(grid, x, y-1, visited);
    result |= detect(grid, x, y+1, visited);

    return result;
}

int main() {
    ofstream fout("lightson.out");
    ifstream fin("lightson.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int,int>> connections[n*n];
    for (int i = 0; i < m; i++){
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        connections[(y-1)*n+x-1].push_back(make_pair(a-1,b-1));
    }

    //Check all possible rooms that can be activated using the current lit rooms
    //Check if the activated rooms can be reached from the already lit rooms
    //Check all the possible rooms that can be activated from the activated rooms
    //Repeat
    int ans = 0;
    grid[0][0] = 1;
    vector<pair<int,int>> que;
    dfs(grid, 0, 0, ans, connections, que);
    while (que.size()){
        vector<pair<int,int>> newQue;
        for (pair<int,int> i: que){
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (detect(grid, i.first, i.second, visited)){
                dfs(grid, i.first, i.second, ans, connections, newQue);
            }
        }
        que = newQue;
    }

    //Output
    fout << ans;

    return 0;
}
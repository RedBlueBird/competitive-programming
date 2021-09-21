#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int Dx[] = {1,0,-1,0};
int Dy[] = {0,1,0,-1};

//Paint adjacent grids in alternating colors with depth-first-search
void bfs(vector<vector<int>>& grid, int x, int y, int color){
    grid[x][y] = color;
    if (color == 1) color = 2;
    else color = 1;
    for (int i = 0; i < 4; i++){
        int dx = x + Dx[i], dy = y + Dy[i];
        if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) continue;
        if (grid[dx][dy] != 0) continue;
        bfs(grid, dx, dy, color);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m,0));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '-')
                grid[i][j] = -1;
        }
    }

    //Initiate depth-first-search
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 0){
                bfs(grid, i, j, 1);
            }
        }
    }

    //Output
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1)
                cout << 'B';
            else if (grid[i][j] == 2)
                cout << 'W';
            else
                cout << '-';
        }
        cout << "\n";
    }

    return 0;
}
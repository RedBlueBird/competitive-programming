#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Possible directions a cow can go to eat grass
int Dx[] = {1,0,-1,0,3,0,-3,0, 2,2,1,1,-1,-1,-2,-2};
int Dy[] = {0,1,0,-1,0,3,0,-3, 1,-1,2,-2,2,-2,1,-1};

int main() {
    ifstream fin("visitfj.in");
    ofstream fout("visitfj.out");
//    ifstream fin("../input.txt");
//    ofstream fout("../output.txt");

    //Take inputs
    int n, t;
    fin >> n >> t;
    vector<vector<int>> field(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fin >> field[i][j];
        }
    }

    //The problem is shortest path that can be solved with dijkstra
    //The cow can only eat every 3 moves, there are 16 possible tiles a cow can reach in 3 moves
    //The distance between reachable tiles in 3 moves is the time it takes to eat the tile + 3 * t
    //If the tile is less than 3 in manhattan to farmer John's tile then those two tiles are also reachable
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(n));
    dist[0][0] = 0;
    priority_queue<pair<int,pii>> dijkstra;
    dijkstra.push(make_pair(0,make_pair(0,0)));
    while (dijkstra.size()){
        int x,y;
        tie(x,y) = dijkstra.top().ss;
        dijkstra.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int i = 0; i < 16; i++){
            int dx = x + Dx[i], dy = y + Dy[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
            if (dist[dx][dy] > dist[x][y] + 3*t + field[dx][dy]){
                dist[dx][dy] = dist[x][y] + 3*t + field[dx][dy];
                dijkstra.push(make_pair(-dist[dx][dy], make_pair(dx,dy)));
            }
        }
        if (n-x-1+n-y-1 < 3){
            dist[n-1][n-1] = min(dist[n-1][n-1], dist[x][y] + (n-x-1+n-y-1)*t);
        }
    }

    //Output
    fout << dist[n-1][n-1];

    return 0;
}


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int Dx[4] = {-1,1,0,0};
int Dy[4] = {0,0,-1,1};
string Dir = "UDLR";

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n,m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> bfs;
    pair<int,int> start;
    for (int i = 0; i < n; i++){
        string raw;
        cin >> raw;
        for (int j = 0; j < m; j++){
            if (raw[j] == '#'){
                map[i][j] = 0;
            }else if (raw[j] == 'M'){
                bfs.push(make_pair(i, j));
                map[i][j] = 0;
            }else if (raw[j] == 'A'){
                start.first = i;
                start.second = j;
            }
        }
    }

    //If starting positive is already at edge, output 0
    //Breath first search the map with the monster first
    //Scan all the monster visitable areas and mark the minimum time to reach there
    //Then bfs again starting from the starting coordinates
    //If it can reach to the edge where the time to reach each grid in the path faster than the monster's minimum time
    //answer will be found
    if (start.first == 0 || start.first == n-1 || start.second == 0 || start.second == m-1){
        cout << "YES\n" << 0;
        return 0;
    }
    while (!bfs.empty()){
        int x,y;
        tie(x,y) = bfs.front(); bfs.pop();
        for (int i = 0; i < 4; i++){
            int dx = x + Dx[i], dy = y + Dy[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if (map[x][y]+1 < map[dx][dy]){
                map[dx][dy] = map[x][y]+1;
                bfs.push(make_pair(dx,dy));
            }
        }
    }
    vector<vector<int>> path(n, vector<int>(m, -1));
    bfs.push(start);
    map[start.first][start.second] = 0;
    pair<int,int> end = {-1,-1};
    while (!bfs.empty()){
        int x,y;
        tie(x,y) = bfs.front(); bfs.pop();
        for (int i = 0; i < 4; i++){
            int dx = x + Dx[i], dy = y + Dy[i];
            if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if (map[x][y]+1 < map[dx][dy]){
                map[dx][dy] = map[x][y]+1;
                path[dx][dy] = i;
                if (dx == 0 || dx == n-1 || dy == 0 || dy == m-1){
                    end.first = dx;
                    end.second = dy;
                    break;
                }
                bfs.push(make_pair(dx,dy));
            }
        }
        if (end != make_pair(-1,-1)) break;
    }

    //Reconstruct the path walked if it made it to the end
    //Other wise, output no
    if (end == make_pair(-1,-1)){
        cout << "NO";
    }else{
        stack<char> ans;
        int ind = path[end.first][end.second];
        while (ind != -1){
            ans.push(Dir[ind]);
            end.first += Dx[ind]*-1;
            end.second += Dy[ind]*-1;
            ind = path[end.first][end.second];
        }
        cout << "YES\n";
        cout << ans.size() << "\n";
        while (!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
    }

    return 0;
}
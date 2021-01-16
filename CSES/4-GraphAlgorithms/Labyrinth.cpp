#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int Dx[4] = {-1,1,0,0};
int Dy[4] = {0,0,-1,1};
string Dir = "UDLR";

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs, mark the beginning and the end
    int n, m;
    cin >> n >> m;
    pair<int,int> start;
    pair<int,int> goal;
    vector<vector<bool>> map(n, vector<bool>(m,false));
    for (int i = 0; i < n; i++){
        string raw;
        cin >> raw;
        for (int j = 0; j < m; j++){
            if (raw[j] == '#'){
                map[i][j] = true;
            }
            else if (raw[j] == 'A'){
                start.first = i;
                start.second = j;
            }
            else if (raw[j] == 'B'){
                goal.first = i;
                goal.second = j;
            }
        }
    }

    //Breath first search through the whole map until goal met or nothing left
    //Use a second matrix with same dimension to track the correct path walked to the goal
    vector<vector<pair<int,int>>> visited(n, vector<pair<int,int>>(m, {0,0}));
    visited[start.first][start.second] = make_pair(-1,-1);
    queue<pair<int,int>> bfs;
    bfs.push(make_pair(start.first, start.second));
    while (!bfs.empty()){
        int x,y;
        tie(x,y) = bfs.front(); bfs.pop();
        for (int i = 0; i < 4; i++) {
            int dx = Dx[i]+x, dy = Dy[i]+y;
            if (dx < 0 || dx >= map.size() || dy < 0 || dy >= map[0].size()) continue;
            if (map[dx][dy]) continue;
            if (visited[dx][dy] != make_pair(0,0)) continue;
            visited[dx][dy] = make_pair(Dx[i]*-1, Dy[i]*-1);
            if (goal.first == dx && goal.second == dy) break;
            bfs.push(make_pair(dx,dy));
        }
    }

    //Output yes if path is found, otherwise no
    //Reverse the path tracking matrix and output the path
    if (visited[goal.first][goal.second] != make_pair(0,0)){
        cout << "YES\n";
        stack<char> ans;
        pair<int,int> curr = goal;
        while (curr != start){
            pair<int,int> dir = visited[curr.first][curr.second];
            curr.first += dir.first; curr.second += dir.second;
            for (int i = 0; i < 4; i++){
                if (dir.first*-1 == Dx[i] && dir.second*-1 == Dy[i])
                    ans.push(Dir[i]);
            }
        }
        cout << ans.size() << "\n";
        while (!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
    }else{
        cout << "NO";
    }

    return 0;
}
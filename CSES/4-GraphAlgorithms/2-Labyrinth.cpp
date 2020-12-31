#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    unsigned int n, m;
    cin >> n >> m;
    pair<unsigned int,unsigned int> start;
    pair<unsigned int,unsigned int> goal;
    vector<vector<bool>> map(n, vector<bool>(m,false));
    for (unsigned int i = 0; i < n; i++){
        string raw;
        cin >> raw;
        for (unsigned int j = 0; j < m; j++){
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

    //Initialize the search
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string ans = "";
    queue<tuple<unsigned int,unsigned int,string>> bfs;
    bfs.push(make_tuple(start.first, start.second, ""));
    while (!bfs.empty()){
        unsigned int x,y; string path;
        tie(x,y, path) = bfs.front(); bfs.pop();
        if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size()) continue;
        if (map[x][y]) continue;
        if (visited[x][y]) continue;
        if (goal.first == x && goal.second == y){
            ans = path;
            break;
        }
        visited[x][y] = true;

        bfs.push(make_tuple(x -1, y , path+"U"));
        bfs.push(make_tuple(x +1, y , path+'D'));
        bfs.push(make_tuple(x , y -1, path+'L'));
        bfs.push(make_tuple(x , y +1, path+'R'));
    }

    //Output yes if path is found, otherwise no
    if (ans != ""){
        cout << "YES\n";
        cout << ans.size() << "\n";
        cout << ans;
    }else{
        cout << "NO";
    }

    return 0;
}
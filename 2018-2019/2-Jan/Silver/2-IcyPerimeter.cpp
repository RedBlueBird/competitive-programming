#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the whole graph, visit all the connected island
//If it touches edge return true, else return false
//The perimeter is added with the edge detection
//Area the added for every new grid visited
bool dfs(vector<vector<bool>>& graph, vector<vector<bool>>& visited, int x, int y, int& area, int& perm){
    if (x < 0 || x >= graph.size() || y < 0 || y >= graph.size()) return true;
    if (visited[x][y]) return false;
    if (!graph[x][y]) return true;
    visited[x][y] = true;
    area++;

    perm += dfs(graph, visited, x +1, y , area,perm);
    perm += dfs(graph, visited, x -1, y , area,perm);
    perm += dfs(graph, visited, x , y +1, area,perm);
    perm += dfs(graph, visited, x , y -1, area,perm);

    return false;
}

int main() {
    ofstream fout("perimeter.out");
    ifstream fin("perimeter.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Cast the input into a map
    //Convert the states into bool
    int n;
    fin >> n;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++){
        string row;
        fin >> row;
        for (int j = 0; j < n; j++){
            if (row[j] == '#'){
                graph[i][j] = true;
            }
        }
    }

    //Find all the uniquely connected island
    //Search for the highest area and least perimeter
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    pair<int,int> ans = {0,0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j]) continue;
            if (!graph[i][j]) continue;
            int area = 0;
            int perm = 0;
            dfs(graph, visited, i, j, area, perm);
            if (ans.first == area && ans.second > perm) {
                ans.second = perm;
            } else if (ans.first < area){
                ans.first = area;
                ans.second = perm;
            }
        }
    }

    //Output the area and the perimeter
    fout << ans.first << " " << ans.second;

    return 0;
}
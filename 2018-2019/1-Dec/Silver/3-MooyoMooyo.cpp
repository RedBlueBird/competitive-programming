#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the whole graph, visit all the adjacent grid with same color
//Count the # of visited grid
void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y, int color, int& count){
    if (x < 0 || x >= graph.size() || y < 0 || y >= 10) return;
    if (visited[x][y]) return;
    if (graph[x][y] != color) return;
    visited[x][y] = true;
    count++;

    dfs(graph, visited, x -1, y , color, count);
    dfs(graph, visited, x +1, y , color, count);
    dfs(graph, visited, x , y -1, color, count);
    dfs(graph, visited, x , y +1, color, count);
}

//If the group of same color grids met the requirement they will get deleted
void pop(vector<vector<int>>& graph, int x, int y, int color){
    if (x < 0 || x >= graph.size() || y < 0 || y >= 10) return;
    if (graph[x][y] != color) return;
    graph[x][y] = 0;

    pop(graph, x -1, y , color);
    pop(graph, x +1, y , color);
    pop(graph, x , y -1, color);
    pop(graph, x , y +1, color);
}

//Move all the colored grids that are floating down to the ground using queue
void fall(vector<vector<int>>& graph){
    for (int i = 0; i < 10; i++){
        queue<int> pit;
        for (int j = graph.size()-1; j >= 0; j--){
            if (graph[j][i] == 0){
                pit.push(j);
            }
            else if (!pit.empty()){
                graph[pit.front()][i] = graph[j][i];
                graph[j][i] = 0;
                pit.push(j);
                pit.pop();
            }
        }
    }
}

int main() {
    ofstream fout("mooyomooyo.out");
    ifstream fin("mooyomooyo.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<vector<int>> graph(n, vector<int>(10,0));
    for (int i = 0; i < n; i++){
        string row;
        fin >> row;
        for (int j = 0; j < 10; j++){
            graph[i][j] = row[j]-'0';
        }
    }

    //Keep dfs and popping and fall until there are no more grids to pop with
    bool popped = true;
    while (popped){
        popped = false;
        vector<vector<bool>> visited(n ,vector<bool>(10, false));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 10; j++){
                if (graph[i][j] == 0) continue;
                if (visited[i][j]) continue;
                int count = 0;
                dfs(graph, visited, i, j, graph[i][j], count);
                if (count >= k){
                    popped = true;
                    pop(graph, i, j, graph[i][j]);
                }
            }
        }
        fall(graph);
    }

    //Output the whole graph
    for (vector<int> i: graph){
        for (int j: i){
            fout << j;
        }
        fout << "\n";
    }

    return 0;
}
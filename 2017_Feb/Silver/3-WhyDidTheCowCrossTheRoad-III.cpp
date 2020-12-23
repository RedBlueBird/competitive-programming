#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Depth first search the whole graph, bond with all the cows possible
//The only cows that can't be bonded are the ones surrounded by roads
//When bonded it will increment to the total bonded cows
void dfs(vector<vector<int>>& graph, int x, int y, vector<vector<bool>>& visited, vector<vector<bool>>& bonds, int& formed, int origin){
    if (x < 0 || x >= graph.size() || y < 0 || y >= graph.size()) return;
    if (graph[x][y] == -1) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    if (graph[x][y] != 0){
        if (graph[x][y] == origin){
            bonds[origin-1][origin-1] = true;
        }
        else if (!bonds[origin-1][graph[x][y]-1]){
            formed++;
            bonds[origin-1][graph[x][y]-1] = true;
            bonds[graph[x][y]-1][origin-1] = true;
        }
    }
    dfs(graph, x -1, y , visited, bonds, formed, origin);
    dfs(graph, x +1, y , visited, bonds, formed, origin);
    dfs(graph, x , y -1, visited, bonds, formed, origin);
    dfs(graph, x , y +1, visited, bonds, formed, origin);
}

int main() {
    ofstream fout("countcross.out");
    ifstream fin("countcross.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k, r;
    fin >> n >> k >> r;
    vector<vector<int>> graph(2*n-1, vector<int>(2*n-1));
    vector<pair<int,int>> cows(k);
    for (int i = 0; i < r; i++){
        int a,b,c,d;
        fin >> a >> b >> c >> d;
        graph[(a-1)*2+c-a][(b-1)*2+d-b] = -1;
    }
    for (int i = 0; i < k; i++){
        int a,b;
        fin >> a >> b;
        graph[(a-1)*2][(b-1)*2] = i+1;
        cows[i] = make_pair((a-1)*2, (b-1)*2);
    }

    //Search all through all the cow pairs and find all the possible bonds
    vector<vector<bool>> bonds(k, vector<bool>(k));
    int ans = 0;
    for (int i = 0; i < k; i++){
        vector<vector<bool>> visited(2*n-1, vector<bool>(2*n-1, false));
        dfs(graph, cows[i].first, cows[i].second, visited, bonds, ans, i+1);
    }

    //The distant pair are the total pairs - bonded pairs
    fout << k*(k-1)/2 - ans;

    return 0;
}
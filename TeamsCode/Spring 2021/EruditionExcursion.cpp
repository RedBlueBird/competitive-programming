#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Floodfill all the cities that are connected to each other
void dfs(map<pii,vector<pii>>& graph, map<pii,bool>& visited, int x, int y, int& total){
    visited[make_pair(x,y)] = true;
    total++;
    for (auto i: graph[make_pair(x,y)]){
        if (visited[i]) continue;
        dfs(graph, visited, i.ff, i.ss, total);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n, m;
    cin >> n >> m;
    map<pii,vector<pii>> graph;
    map<pii,bool> visited;
    vector<pii> coords;
    for (int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c>> d;
        graph[make_pair(a,b)].push_back(make_pair(c,d));
        graph[make_pair(c,d)].push_back(make_pair(a,b));
        visited[make_pair(a,b)] = false;
        visited[make_pair(c,d)] = false;
        coords.push_back(make_pair(a,b));
        coords.push_back(make_pair(c,d));
    }

    //Find all the connected components with depth-first-search
    int ans = n*n;
    for (int i = 0; i < 2*m; i++){
        if (visited[coords[i]]) continue;
        int total = 0;
        dfs(graph, visited, coords[i].ff, coords[i].ss, total);
        ans += total*(total-1);
    }

    //Output
    cout << ans;

    return 0;
}
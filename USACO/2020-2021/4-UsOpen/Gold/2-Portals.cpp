#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Find all the cycles in the graph
void dfs(vector<vector<int>>& graph, vector<vector<int>>& portal, vector<vector<bool>>& visited, vector<vector<int>>& cycles, int node, int type, int cycle){
    visited[node][type] = true;
    cycles[node][type] = cycle;
    for (int i = type*2; i < type*2+2; i++){
        int next;
        int ntype;
        if (portal[graph[node][i]][0] != node)
            next = portal[graph[node][i]][0];
        else
            next = portal[graph[node][i]][1];
        if (graph[next][0] != graph[node][i] && graph[next][1] != graph[node][i])
            ntype = 1;
        else
            ntype = 0;
        if (visited[next][ntype]) continue;
        dfs(graph, portal, visited, cycles, next, ntype, cycle);
    }
}

//Find the root of the tree the current cycle resides in
int find(vector<int>& top, int k){
    return k == top[k] ? k : top[k] = find(top, top[k]);
}

//Merge two cycles if possible
bool merge(vector<int>& top, vector<int>& size, int a, int b){
    a = find(top, a);
    b = find(top, b);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a,b);
    top[b] = a;
    size[a] += b;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n;
    cin >> n;
    vector<int> cost(n+1);
    vector<vector<int>> graph(n+1, vector<int>(4));
    vector<vector<int>> portal(2*n+1);
    for (int i = 1; i <= n; i++){
        cin >> cost[i];
        for (int j = 0; j < 4; j++) {
            cin >> graph[i][j];
            portal[graph[i][j]].push_back(i);
        }
    }

    //Find all cycles
    //Each node will contain 1 or 2 cycles
    //The cost of that node will merge the cycles that passes through that node
    //The problem is now reduced to minimum spanning tree
    //Where you find the least possible cost to merge all cycles
    //(cycles can be treated as "node" during this part)
    int cycle = 1;
    vector<vector<bool>> visited(n+1, vector<bool>(2));
    vector<vector<int>> cycles(n+1, vector<int>(2));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            if (visited[i][j]) continue;
            dfs(graph, portal, visited, cycles, i, j, cycle);
            cycle++;
        }
    }
    vector<tiii> edges;
    for (int i = 1; i <= n; i++){
        edges.push_back(make_tuple(cost[i], cycles[i][0], cycles[i][1]));
    }
    sort(edges.begin(), edges.end());

    //Merge cycles from the order with the lowest merging cost
    int ans = 0;
    vector<int> top(cycle);
    vector<int> size(cycle, 1);
    for (int i = 1; i <= cycle; i++)
        top[i] = i;
    for (int i = 0; i < edges.size(); i++){
        if (merge(top, size, get<1>(edges[i]), get<2>(edges[i])))
            ans += get<0>(edges[i]);
    }

    //Output
    cout << ans;

    return 0;
}
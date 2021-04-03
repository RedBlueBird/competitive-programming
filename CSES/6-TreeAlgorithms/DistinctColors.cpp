#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Small-large merging technique for dp on trees
//This allows each node to be only be swapped at most O(n*log(n)) times
//(Proof left as an exercise to the reader)
void dfs(vector<vector<int>>& graph, vector<int>& parent, vector<int>& values, vector<int>& ans, vector<set<int>>& infos, int node){
    infos[node].insert(values[node]);
    for (int i: graph[node]){
        if (i == parent[node]) continue;
        parent[i] = node;
        dfs(graph, parent, values, ans, infos, i);
        if (infos[node].size() < infos[i].size()) swap(infos[node], infos[i]);
        for (auto j: infos[i]){
            infos[node].insert(j);
        }
    }
    ans[node] = infos[node].size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Construct a tree graph
    int n;
    cin >> n;
    vector<int> values(n+1);
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Use small-large merging on trees
    //Each node carries information about the total distinct colors in its subtree
    //The answer to each node is the size of the color set it carries
    vector<int> parent(n+1);
    vector<int> ans(n+1);
    vector<set<int>> infos(n+1);
    dfs(graph, parent, values, ans, infos, 1);

    //Output
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
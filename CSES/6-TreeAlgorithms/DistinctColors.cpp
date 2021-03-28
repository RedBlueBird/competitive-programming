#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

void debug(vector<int>& a){
    for (int i: a){
        cout << i << " ";
    }
    cout << "\n ---- \n";
}

void debug(map<int,int>& a){
    for (auto i: a){
        cout << i.first << " : " << i.second << "\n";
    }
    cout << " \n ------- \n";
}

void debug(vector<vector<int>>& a){
    for (vector<int> i: a){
        for (int j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << " \n ------ \n";
}

void dfs(vector<vector<int>>& graph, vector<int>& parent, vector<int>& size, vector<int>& depth, vector<int>& heavy, int node){
    int max_size = 0;
    for (int i: graph[node]){
        if (i == parent[node]) continue;
        parent[i] = node;
        depth[i] = depth[node] + 1;
        dfs(graph, parent, size, depth, heavy, i);
        if (size[i] > max_size){
            max_size = size[i];
            heavy[node] = i;
        }
        size[node] += size[i];
    }
}

void decompose(vector<vector<int>>& graph, vector<int>& parent, vector<int>& tail, vector<int>& heavy, int node){
    if (heavy[node]){
        decompose(graph, parent, tail, heavy, heavy[node]);
        tail[node] = tail[heavy[node]];
    }else{
        tail[node] = node;
    }
    for (int i: graph[node]){
        if (i == parent[node] || i == heavy[node]) continue;
        decompose(graph, parent, tail, heavy, i);
    }
}

void condense(vector<vector<int>>& graph, vector<vector<pii>>& condensed, vector<int>& parent, vector<int>& tail, map<int,int>& reduce, vector<int>& depth, int node){
    for (int i: graph[node]){
        if (i == parent[node]) continue;
        if (tail[i] != tail[node])
            condensed[reduce[tail[node]]].push_back(make_pair(reduce[tail[i]], depth[i]));
        condense(graph, condensed, parent, tail, reduce, depth, i);
    }
}

void find(vector<vector<pii>>& condensed, vector<vector<int>>& groups, vector<int>& sums, int node, int& value, int& total, int& depth){
    if (groups[node][value]){
        groups[node][value]--;
        sums[node]--;
    }
    total += sums[node];
    for (pii i: condensed[node]){
        if (depth < i.ss)
            find(condensed, groups, sums, i.ff, value, total, depth);
    }
}

void solve(vector<vector<int>>& graph, vector<vector<pii>>& condensed, vector<int>& values, vector<int>& parent, vector<int>& tail, vector<vector<int>>& groups, map<int,int>& reduce, map<int,int>& convert, vector<int>& sums, vector<int>& depth, vector<int>& ans, int node){
    for (int i: graph[node]){
        if (i == parent[node]) continue;
        solve(graph, condensed, values, parent, tail, groups, reduce, convert,sums, depth, ans, i);
    }
    find(condensed, groups, sums, reduce[tail[node]], convert[values[node]], ans[node], depth[node]);
    ans[node]++;
    groups[reduce[tail[node]]][convert[values[node]]]++;
    sums[reduce[tail[node]]]++;
//    cout << node << "\n";
//    debug(groups);
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n;
    cin >> n;
    vector<int> values(n+1);
    for (int i = 1; i <= n; i++){
        cin >> values[i];
    }
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> tail(n+1);
    vector<int> parent(n+1, 1);
    vector<int> size(n+1,1);
    vector<int> heavy(n+1);
    vector<int> depth(n+1);
    dfs(graph, parent, size, depth, heavy, 1);
    decompose(graph, parent, tail, heavy, 1);

    vector<int> compress = values;
    map<int,int> convert;
    sort(compress.begin(), compress.end());
    for (int i = 1; i <= n; i++){
        if (!convert.count(compress[i]))
            convert[compress[i]] = i;
    }
    int c = 1;
    map<int,int> reduce;
    for (int i = 1; i <= n; i++){
        if (!reduce.count(tail[i]))
            reduce[tail[i]] = c++;
    }
    vector<vector<int>> groups(c, vector<int>(n+1));
    vector<vector<pii>> condensed(c);
    vector<int> sums(c);
    condense(graph, condensed, parent, tail, reduce, depth, 1);
//    debug(tail);
//    debug(sums);
//    debug(reduce);

    vector<int> ans(n+1);
    solve(graph, condensed, values, parent, tail, groups, reduce, convert,sums, depth, ans, 1);

    //Output
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
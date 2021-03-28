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

void debug(vector<vector<pii>>& a){
    for (vector<pii> i: a){
        for (pii j: i){
            cout << "(" << j.ff << "," << j.ss << ") ";
        }
        cout << "\n";
    }
    cout << " \n ------ \n";
}

void debug(vector<pii>& a){
    for (pii j: a){
        cout << "(" << j.ff << "," << j.ss << ") ";
    }
    cout << " \n ------ \n";
}

const int N = 1e5+1;
vector<int> graph[N];
int values[N], size[N], depth[N], head[N], parent[N], heavy[N];
map<int,int> reduce;

void decompose(vector<vector<int>>& graph, vector<int>& parent, vector<int>& heavy, vector<int>& head, int node){
    if (heavy[node]){
        head[heavy[node]] = head[node];
        decompose(graph, parent, heavy, head, heavy[node]);
    }
    for (int i: graph[node]){
        if (i == parent[node] || i == heavy[node]) continue;
        head[i] = i;
        decompose(graph, parent, heavy, head, i);
    }
}

void fill_color(vector<vector<int>>& graph, vector<vector<pii>>& groups, map<int,int>& reduce, vector<int>& parent, vector<int>& values, vector<int>& head, vector<int>& depth, int node){
    groups[reduce[head[node]]][values[node]].ff = max(depth[node],groups[reduce[head[node]]][values[node]].ff);
    groups[reduce[head[node]]][values[node]].ss = min(depth[node],groups[reduce[head[node]]][values[node]].ss);
    for (int i : graph[node]){
        if (i == parent[node]) continue;
        fill_color(graph, groups, reduce, parent, values, head, depth, i);
    }
}

bool query(vector<vector<int>>& graph, vector<vector<pii>>& groups, map<int,int>& reduce, vector<int>& parent, vector<int>& depth, vector<int>& head, int a, int b, int value){
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (depth[a] > depth[b]) swap(a,b);
        int search = groups[reduce[head[b]]][value].ss;
//        cout << search << " " << depth[b] << " " << b << " " << value << "\n";
//        debug(groups[reduce[head[b]]]);
        if (search <= depth[b]) return true;
    }
    int up, down;
    tie(down, up) = groups[reduce[head[a]]][value];
//    cout << up << " " << down << " " << depth[a] << " " << depth[b] << "\n";
    if (depth[a] >= up && depth[a] <= down) return true;
    if (depth[b] >= up && depth[b] <= down) return true;
    return false;
}

int main() {
//    ofstream fout("milkvisits.out");
//    ifstream fin("milkvisits.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<int> values(n+1);
    for (int i = 1; i <= n; i++){
        fin >> values[i];
    }
    for (int i = 1; i < n; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> size(n+1,1);
    vector<int> depth(n+1);
    vector<int> heavy(n+1);
    vector<int> head(n+1);
    depth[1] = 1;
    head[1] = 1;
    stack<int> dfs;
    dfs.push(1);
    while (dfs.size()){
        int node = dfs.top();
        dfs.pop();
        int max_size = 0;
        for (int i: graph[node]){
            if (i == parent[node]) continue;
            depth[i] = depth[node] + 1;
            parent[i] = node;
            dfs.push(i);
        if (size[i] > max_size){
            heavy[node] = i;
            max_size = size[i];
        }
        size[node] += size[i];
        }
    }
//    decompose(graph, parent, heavy, head, 1);
//    int c = 0;
//    map<int,int> reduce;
//    for (int i = 1; i <= n; i++){
//        if (!reduce.count(head[i]))
//            reduce[head[i]] = c++;
//    }
//    vector<vector<pii>> groups(c, vector<pii>(n+1));
//    for (int i = 0; i < c; i++){
//        for (int j = 0; j <= n; j++){
//            groups[i][j] = make_pair(0, INT_MAX);
//        }
//    }
//    fill_color(graph, groups, reduce, parent, values, head, depth, 1);

//    debug(groups);
//    debug(head);
//    debug(reduce);
//    for (int i = 0; i < m; i++){
//        int a,b,c;
//        fin >> a >> b >> c;
//        fout << query(graph, groups, reduce, parent, depth, head, a, b, c);
//    }

    return 0;
}


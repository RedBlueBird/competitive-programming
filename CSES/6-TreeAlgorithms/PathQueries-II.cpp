#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Find the maximum value between range a b in segment tree
int maximum(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    int maxs = 0;
    while (a <= b){
        if (a%2)
            maxs = max(maxs, segtree[a++]);
        if (!(b%2))
            maxs = max(maxs, segtree[b--]);
        a /= 2;
        b /= 2;
    }
    return maxs;
}

//Set the k-th value to x in segment tree
void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = max(segtree[2*k], segtree[2*k+1]);
    }
}

//Find the size, depth, and heavy edges for the tree graph
void initialize(vector<vector<int>>& graph, vector<int>& parent, vector<int>& size, vector<int>& depth, vector<int>& heavy, int node){
    int max_size = 0;
    for (int i: graph[node]){
        if (i == parent[node]) continue;
        depth[i] = depth[node] + 1;
        parent[i] = node;
        initialize(graph, parent, size, depth, heavy, i);
        int curr_size = size[i];
        if (curr_size > max_size){
            max_size = curr_size;
            heavy[node] = i;
        }
        size[node] += size[i];
    }
}

//Heavy-light decompose the graph
//Separate the tree graph nodes into linked-lists
void decompose(vector<vector<int>>& graph, vector<int>& parent, vector<int>& depth, vector<int>& heavy, vector<int>& head, vector<int>& pos, int node, int& order){
    pos[node] = order++;
    if (heavy[node]) {
        head[heavy[node]] = head[node];
        decompose(graph, parent, depth, heavy, head, pos, heavy[node], order);
    }
    for (int i: graph[node]){
        if (i == parent[node] || i == heavy[node]) continue;
        head[i] = i;
        decompose(graph, parent, depth, heavy, head, pos, i, order);
    }
}

//Return the maximum value between two nodes in a tree graph
//With a log(N)^2 time using the help of the heavy-light decomposition
int max_query(vector<int>& segtree, vector<int>& head, vector<int>& parent, vector<int>& depth, vector<int>& pos, int a, int b){
    int maxs = 0;
    int curr_max = 0;
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (depth[head[a]] > depth[head[b]]) swap(a,b);
        curr_max = maximum(segtree, pos[head[b]], pos[b]);
        maxs = max(maxs, curr_max);
    }
    if (depth[a] > depth[b]) swap(a,b);
    curr_max = maximum(segtree, pos[a], pos[b]);
    maxs = max(maxs, curr_max);
    return maxs;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Construct a tree graph with adjacency list
    int n, q;
    cin >> n >> q;
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

    //Construct linked-lists from tree using heavy-light decomposition
    vector<int> parent(n+1, 1);
    vector<int> head(n+1, 1);
    vector<int> pos(n+1);
    vector<int> depth(n+1);
    vector<int> size(n+1, 1);
    vector<int> heavy(n+1);
    int order = 0;
    initialize(graph, parent, size, depth, heavy, 1);
    decompose(graph, parent, depth, heavy, head, pos, 1, order);

    //Construct maximum segment tree over the input tree using order from linked-lists
    int len = 0;
    while ((1 << len) <= n) len++;
    len = 1 << len;
    vector<int> segtree(2*len);
    for (int i = 1; i <= n; i++){
        segtree[len+pos[i]] = values[i];
    }
    for (int i = len/2; i >= 1; i /= 2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = max(segtree[2*j], segtree[2*j+1]);
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1){
            update(segtree, pos[a], b);
        }else{
            cout << max_query(segtree, head, parent, depth, pos, a, b) << " ";
        }
    }

    return 0;
}
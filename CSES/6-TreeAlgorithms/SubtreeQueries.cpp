#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Get the time it took to reach the node first time, and its subtree size
void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& index, vector<int>& size, int node, int& count){
    visited[node] = true;
    count++;
    index[node] = count;
    for (int i: graph[node]){
        if (visited[i]) continue;
        dfs(graph, visited, index, size, i, count);
        size[node] += size[i];
    }
}

//Sum the values in the range a to b of a segment tree
ll sumTree(vector<ll>& segtree, int a, int b){
    int c = segtree.size()/2;
    a += c;
    b += c;
    ll s = 0;
    while (a <= b){
        if (a%2)
            s += segtree[a++];
        if (!(b%2))
            s += segtree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

//Set the k-th node's value to x in the segment tree
void setNode(vector<ll>& segtree, int k, ll x){
    int c = segtree.size()/2;
    k += c;
    segtree[k] = x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Get the segment tree's tree size
    //Construct tree graph
    int n, q;
    cin >> n >> q;
    int c = 0;
    while( (1 << c) <= n)
        c++;
    c = 1 << c;
    vector<ll> weight(n+1);
    for (int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //Dfs the tree graph to collect all the required data
    //Construct segment tree with tree node's values
    //The subtree sum can be obtained in log(n) time with segment tree
    //The range sum is equal to sum(index[node], index[node] + size[node])
    vector<bool> visited(n+1, false);
    vector<int> index(n+1,0);
    vector<int> size(n+1, 1);
    vector<ll> segtree(2*c);
    int count = 0;
    dfs(graph, visited, index, size, 1, count);
    for (int i = 1; i <= n; i++){
        segtree[c+index[i]] = weight[i];
    }
    for (int i = c/2; i >= 1; i /= 2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = segtree[2*j] + segtree[2*j+1];
        }
    }

    //Output
    //Change node's value when asked
    //Output range sum (subtree sum) when needed
    for (int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            int a; ll b;
            cin >> a >> b;
            setNode(segtree, index[a], b);
        }else{
            int a;
            cin >> a;
            cout << sumTree(segtree, index[a], index[a]+size[a]-1) << "\n";
        }
    }

    return 0;
}
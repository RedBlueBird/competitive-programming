#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Dfs the tree to get the position and subtree size of each node
void construct(vector<vector<int>>& graph, vector<bool>& visited, vector<ll>& weights, vector<int>& position, vector<int>& size, vector<ll>& segtree, int node, int& c){
    int len = segtree.size()/2;
    visited[node] = true;
    position[node] = c;
    segtree[len+c] += weights[node];
    c++;
    for (int i: graph[node]){
        if (visited[i]) continue;
        segtree[len+c] = segtree[len+position[node]];
        construct(graph, visited, weights, position, size, segtree, i, c);
        size[node] += size[i];
    }
}

//Increase the k-th element of the segtree by x
void changeValue(vector<ll>& segtree, int k, ll x){
    int len = segtree.size()/2;
    k+=len;
    segtree[k] += x;
    for (k/=2; k >= 1; k/=2){
        segtree[k] = segtree[2*k]+segtree[2*k+1];
    }
}

//Get the range sum between a-th and b-th elements of a segtree
ll rangeSum(vector<ll>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    ll s = 0;
    while (a<=b){
        if (a%2)
            s += segtree[a++];
        if (!(b%2))
            s += segtree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct tree graph
    int n, q;
    cin >> n >> q;
    vector<ll> weights(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int len = 0;
    while ((1<<len)<=n) {
        len++;
    }
    len = (1<<len);

    //Get prefix-sum segment tree through dfs construction
    //Get the difference-sum of the prefix sum and construct the segment tree
    //So it can achieve range update point sum
    vector<bool> visited(n+1);
    vector<int> position(n+1);
    vector<int> size(n+1,1);
    vector<ll> segtree(2*len);
    int c = 1;
    construct(graph, visited, weights,position, size, segtree, 1, c);
    for (int i = len; i < 2*len-1; i++){
        segtree[i] = segtree[i+1]-segtree[i];
    }
    for (int i = len/2; i >= 1; i/=2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = segtree[2*j]+segtree[2*j+1];
        }
    }

    //Output node path sum when asked, range update when needed
    for (int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            int k; ll x;
            cin >> k >> x;
            x -= weights[k];
            weights[k] += x;
            changeValue(segtree, position[k]-1, x);
            changeValue(segtree, position[k]+size[k]-1, -x);
        }else{
            int a;
            cin >> a;
            cout << rangeSum(segtree, 0, position[a]-1) << "\n";
        }
    }

    return 0;
}
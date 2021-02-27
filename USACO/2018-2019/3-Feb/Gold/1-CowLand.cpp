#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//<comment>
//This is currently the longest code I ever wrote for a gold problem
//3.5 hours of debugging time
//</comment>

//EulerTour the tree to find the position and depth of each node
void eulerTour(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& tour, vector<int>& depth, vector<int>& index, int node, int deepness){
    visited[node] = true;
    index[node] = tour.size();
    tour.push_back(node);
    depth.push_back(deepness);
    for (int i: graph[node]){
        if (visited[i]) continue;
        eulerTour(graph, visited, tour, depth, index, i, deepness+1);
        tour.push_back(node);
        depth.push_back(deepness);
    }
}

//Squash the tree into an single array with dfs
//Get the size, position, and accumulate XOR sum of each node
void construct(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& weights, vector<int>& position, vector<int>& size, vector<int>& segtree, int node, int& c){
    int len = segtree.size()/2;
    visited[node] = true;
    position[node] = c;
    segtree[len+c] ^= weights[node];
    c++;
    for (int i: graph[node]){
        if (visited[i]) continue;
        segtree[len+c] = segtree[len+position[node]];
        construct(graph, visited, weights, position, size, segtree, i, c);
        size[node] += size[i];
    }
}

//XOR the k-th element of the segment with x
void changeValue(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k+=len;
    segtree[k] ^= x;
    for (k/=2; k >= 1; k/=2){
        segtree[k] = segtree[2*k]^segtree[2*k+1];
    }
}

//Find the XOR sum between a-th and b-th element of the segment tree
int rangeSum(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    int s = 0;
    while (a<=b){
        if (a%2)
            s ^= segtree[a++];
        if (!(b%2))
            s ^= segtree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

int main() {
    ofstream fout("cowland.out");
    ifstream fin("cowland.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct tree graph
    int n, q;
    fin >> n >> q;
    vector<int> weights(n+1);
    for (int i = 1; i <= n; i++) {
        fin >> weights[i];
    }
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int len = 0;
    while ((1<<len)<=n) len++;
    len = (1<<len);

    //EulerTour the tree graph
    //Precompute the LCM of the tree with sparse table
    vector<bool> visited(n+1);
    vector<int> tour;
    vector<int> depth;
    vector<int> index(n+1);
    eulerTour(graph, visited, tour, depth, index, 1, 1);
    int nn = 2*n-1;
    vector<int> log(nn+1);
    for (int i = 2; i <= nn; i++) {
        log[i] = log[i / 2] + 1;
    }
    vector<vector<pii>> sparse(nn, vector<pii>(log[nn]+1));
    for (int i = 0; i < nn; i++) {
        sparse[i][0] = make_pair(depth[i], tour[i]);
    }
    for (int j = 1; j <= log[nn]; j++){
        for (int i = 0; i + (1 << j) <= nn; i++){
            if (sparse[i][j-1].ff < sparse[i+(1<<(j-1))][j-1].ff){
                sparse[i][j] = sparse[i][j-1];
            }else{
                sparse[i][j] = sparse[i + (1<<(j-1))][j-1];
            }
        }
    }

    //Use prefix segment tree to precompute the XOR path sum of each node
    //Get the difference sum of the prefix segment to do range update point sum
    fill(visited.begin(),visited.end(),0);
    vector<int> position(n+1);
    vector<int> size(n+1,1);
    vector<int> segtree(2*len);
    int c = 1;
    construct(graph, visited, weights,position, size, segtree, 1, c);
    for (int i = len; i < 2*len-1; i++){
        segtree[i] = segtree[i+1]^segtree[i];
    }
    for (int i = len/2; i >= 1; i/=2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = segtree[2*j]^segtree[2*j+1];
        }
    }

    //For each query
    //Range XOR update with difference sum segment tree
    //Answer to the XOR sum between a,b is same as sum(0,a)^sum(0,b)^lcm(a,b)
    for (int i = 0; i < q; i++){
        int type;
        fin >> type;
        if (type == 1){
            int k; int x;
            fin >> k >> x;
            x ^= weights[k];
            weights[k] ^= x;
            changeValue(segtree, position[k]-1, x);
            changeValue(segtree, position[k]+size[k]-1, x);
        }
        else{
            int a,b, apos, bpos, lcm;
            fin >> a >> b;
            apos = index[a];
            bpos = index[b];
            if (apos > bpos) swap(apos, bpos);
            int k = log[bpos-apos+1];
            if (sparse[apos][k].ff < sparse[bpos - (1<<k) + 1][k].ff)
                lcm = sparse[apos][k].ss;
            else
                lcm = sparse[bpos - (1<<k) + 1][k].ss;
            a = rangeSum(segtree, 0, position[a]-1);
            b = rangeSum(segtree, 0, position[b]-1);
            fout << ((a ^ b) ^ weights[lcm]) << "\n";
        }
    }

    return 0;
}

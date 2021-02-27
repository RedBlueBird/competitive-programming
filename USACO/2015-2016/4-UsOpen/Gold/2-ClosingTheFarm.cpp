#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the root of the subtree the node resides in
int find(vector<int>& top, int k){
    return k == top[k] ? k : top[k] = find(top, top[k]);
}

//Merge the two subtrees two nodes resides in if possible
bool merge(vector<int>& top, vector<int>& size, int a, int b){
    a = find(top,a);
    b = find(top,b);
    if (a == b) return false;
    if (size[a]<size[b]) swap(a,b);
    size[a] += size[b];
    top[b] = a;
    return true;
}

int main() {
    ofstream fout("closing.out");
    ifstream fin("closing.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct adjacency graph
    int n, m;
    fin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> query(n);
    for (int i = n-1; i >= 0; i--){
        fin >> query[i];
    }

    //Perform offline query with disjoint-set-union data structure
    //Reverse the query, for all the edges the current farm that just opened can be merged into
    //the total separate components so far can be decreased by 1
    vector<int> top(n+1);
    vector<int> size(n+1,1);
    vector<bool> activated(n+1, false);
    vector<bool> ans(n);
    for (int i = 0; i <= n; i++)
        top[i] = i;
    int components = 0;
    for (int i = 0; i < n; i++){
        int node = query[i];
        components++;
        activated[node] = true;
        for (int j: graph[node]){
            if (!activated[j]) continue;
            if (merge(top, size, node, j)){
                components--;
            }
        }
        if (components == 1)
            ans[i] = true;
    }

    //Output
    for (int i = n-1; i >= 0; i--){
        if (ans[i])
            fout << "YES\n";
        else
            fout << "NO\n";
    }

    return 0;
}


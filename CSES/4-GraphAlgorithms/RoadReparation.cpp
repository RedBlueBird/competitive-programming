#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the root of the node's subtree
int find(vector<int>& top, int target){
    return target == top[target] ? target : top[target] = find(top, top[target]);
}

//Merge 2 subtrees into 1
bool merge(vector<int>& top, vector<int>& sizes, int a, int b){
    a = find(top, a);
    b = find(top, b);
    if (a == b) return false;
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    top[b] = a;
    return true;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct an edge list
    int n, m;
    cin >> n >> m;
    vector<tiii> edges(m);
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = make_tuple(c,a,b);
    }
    sort(edges.begin(), edges.end());

    //Perform minimum spanning tree algorithm
    //When finished, if the maximum size is less than the total amount of nodes
    //the answer would be impossible since not all nodes are connected
    vector<int> top(n+1);
    vector<int> sizes(n+1,1);
    for (int i = 0; i <= n; i++)
        top[i] = i;
    ll ans = 0;
    for (auto i: edges){
        int a,b,c;
        tie(a,b,c) = i;
        if (merge(top,sizes,b,c))
            ans += a;
    }
    int size = 0;
    for (int i: sizes)
        size = max(size, i);

    //Output
    if (size != n)
        cout << "IMPOSSIBLE";
    else
        cout << ans;

    return 0;
}
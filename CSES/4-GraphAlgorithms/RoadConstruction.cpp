#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the root of the node's subtree
int find(vector<int>& top, int k){
    return k == top[k] ? k : top[k] = find(top, top[k]);
}

//Merge 2 subtrees into 1
bool merge(vector<int>&top, vector<int>&sizes, int a, int b, int& maxs){
    a = find(top, a);
    b = find(top,b);
    if (a == b) return false;
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    top[b] = a;
    maxs = max(sizes[a], maxs);
    return true;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;

    //Use union-find data structure
    //If two subtrees are merged, 1 less connected component
    //If the new subtree size is larger than the previous maximum,
    //set the new maximum to this new size
    vector<int> top(n+1);
    vector<int> sizes(n+1,1);
    for (int i = 0; i <= n; i++)
        top[i] = i;
    int maxs = 1;
    int total = n;
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        if (merge(top,sizes,a,b,maxs)){
            total--;
        }
        cout << total << " " << maxs << "\n";
    }

    return 0;
}
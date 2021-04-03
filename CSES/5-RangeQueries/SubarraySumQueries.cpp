#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//For the nodes of a segment tree
//sum: the total sum of values in the range the node covers
//lsum: the max prefix sum from left in the range the node covers
//rsum: the max prefix sum from right in the range the node covers
//best: the max prefix sum of a subarray in the range the node covers
struct Node{
    ll sum, lsum, rsum, best;
    Node operator +(Node b){
        return {sum + b.sum,
                max(lsum, sum+b.lsum),
                max(b.rsum, rsum+b.sum),
                max(max(best,b.best), rsum + b.lsum)
        };
    }
};

//Set the k-th node of a segment tree to x
void update(vector<Node>& segtree, int k, ll x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = {x,max(x,0ll),max(x,0ll),max(x,0ll)};
    for (k /= 2; k >= 1; k/=2)
        segtree[k] = segtree[2*k] + segtree[2*k+1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n, q;
    cin >> n >> q;

    //Dynamic programming on segment tree queries
    //Construct a segment tree with nodes that are from Struct defined above
    int len = 0;
    while ((1 << len) <= n) len++;
    len = (1 << len);
    vector<Node> segtree(2*len);
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        segtree[i+len] = {a,max(a,0ll),max(a,0ll),max(a,0ll)};
    }
    for (int i = len/2; i >= 1; i /= 2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = segtree[2*j] + segtree[2*j+1];
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        ll k, x;
        cin >> k >> x;
        update(segtree, k, x);
        cout << segtree[1].best << "\n";
    }

    return 0;
}
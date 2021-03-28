#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Set the k-th element in the segment tree to x
void update(vector<ll>& segtree, int k, ll x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = x;
    for (k/=2; k >= 1; k/=2){
        segtree[k] = min(segtree[2*k], segtree[2*k+1]);
    }
}

//Find the minimum value between elements in range a and b in the segment tree
ll mins(vector<ll>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    ll minimum = LONG_LONG_MAX;
    while (a <= b){
        if (a%2) {
            minimum = min(minimum, segtree[a++]);
        }
        if (!(b%2)) {
            minimum = min(minimum, segtree[b--]);
        }
        a /= 2;
        b /= 2;
    }
    return minimum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //construct segment tree
    int n, a, b;
    cin >> n >> a >> b;
    int len = 0;
    while ((1 << len) <= n) len++;
    len = 1 << len;
    vector<ll> segtree(2*len, 0);

    //The sum of a subarray is equal to the difference between two prefix sum
    //In order to maximize the subarray sum, we want the smaller prefix sum to be minimized
    //The smaller prefix sum's index have to be between range a,b away from the current index
    //A segment tree data structure can support the minimum prefix query in O(log(N)) time
    ll ans = LONG_LONG_MIN;
    ll curr = 0;
    ll psum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> curr;
        psum += curr;
        update(segtree, i, psum);
        if (i-a >= 0){
            ans = max(ans, psum - mins(segtree, max(i-b,0), i-a));
        }
    }

    //Output
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Increase k-th element in the binary indexed tree by x
void add(vector<ll>& bitree, int k, ll x){
    while (k < int(bitree.size())){
        bitree[k]+=x;
        k += k&-k;
    }
}

//Return the total sum of all elements from 0 to k
ll sum(vector<ll>& bitree, int k){
    ll s = 0;
    while (k){
        s += bitree[k];
        k -= k&-k;
    }
    return s;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct Binary Indexed Tree with Difference Sum
    int n, q;
    cin >> n >> q;
    vector<ll> bitree(n+2);
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        add(bitree, i, a);
        add(bitree, i+1, -a);
    }

    //For each query, range update when needed, output element value when asked
    for (int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            ll a,b,u;
            cin >> a >> b >> u;
            add(bitree, a, u);
            add(bitree, b+1, -u);
        }else{
            ll k;
            cin >> k;
            cout << sum(bitree, k) << "\n";
        }
    }

    return 0;
}
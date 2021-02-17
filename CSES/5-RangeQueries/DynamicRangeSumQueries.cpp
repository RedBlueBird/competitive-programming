#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Sums the numbers from index 0 to index k in BIT
ll sum(vector<ll>& bitree, int k){
    ll s = 0;
    while (k >= 1){
        s += bitree[k];
        k -= k&-k;
    }
    return s;
}

//Add value to the k-th position of the BIT
void add(vector<ll>& bitree, int k, ll x){
    while (k <= int(bitree.size())){
        bitree[k] += x;
        k += k&-k;
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct BIT
    int n, m;
    cin >> n >> m;
    vector<ll> bitree(n+1);
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        add(bitree, i, a);
    }

    //Pretty straight-forward, just need to know Binary-Index-Tree
    //Add when adding is required
    //Return range sum when needed
    for (int i = 0; i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if (a == 1){
            ll diff = c - (sum(bitree, b)-sum(bitree,b-1));
            add(bitree, b, diff);
        }else{
            cout << sum(bitree,c)-sum(bitree,b-1) << "\n";
        }
    }

    return 0;
}
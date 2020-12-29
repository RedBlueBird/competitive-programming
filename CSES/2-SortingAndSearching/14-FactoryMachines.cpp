#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Determines if the chosen time can process k products
bool bisearch(vector<ll>& machines, ll time, ll k){
    ll total = 0;
    for (ll i: machines){
        total += time/i;
        if (total >= k) return true; //Deal overflow
    }
    return total >= k;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n, k;
    cin >> n >> k;
    vector<ll> machines(n);
    for (int i = 0; i < n; i++)
        cin >> machines[i];

    //Binary search the most optimal answer
    ll a = 0;
    ll b = 1e18;
    while ((b-a)>1){
        ll mid = (a+b)/2;
        if (bisearch(machines, mid, k)){
            b = mid;
        }
        else{
            a = mid+1;
        }
    }
    if (!bisearch(machines, a, k)) a = b;

    //Output
    cout << a;

    return 0;
}
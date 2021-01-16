#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n;
    cin >> n;

    //Outputting the answer while taking inputs along the way
    //The pattern can be described in the following formula
    for (ll i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;

        ll c = max(a,b);
        ll d = (c-1)*(c-1);

        ll ans = d;
        if (c%2){
            if (c==a) ans += b;
            else ans += 2 * c - a;
        }
        else{
            if (c==b) ans += a;
            else ans += 2 * c - b;
        }
        cout << ans << "\n";
    }


    return 0;
}
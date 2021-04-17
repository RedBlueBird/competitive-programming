#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a,b)) * b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    ll a,b,c,d,n;
    cin >> a >> b >> c >> d >> n;

    //Can be solved using principle of inclusion and exclusion
    ll ans = n/a + n/b + n/c + n/d;
    ans -= n/lcm(a,b) + n/lcm(a,c) + n/lcm(a,d) + n/lcm(b,c) + n/lcm(b,d) + n/lcm(c,d);
    ans += n/lcm(lcm(a,b),c) + n/lcm(lcm(a,b),d) + n/lcm(lcm(a,c),d) + n/lcm(lcm(b,c),d);
    ans -= n/lcm(lcm(a,b),lcm(c,d));

    //Output
    cout << ans;

    return 0;
}
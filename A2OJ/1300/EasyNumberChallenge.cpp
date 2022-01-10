#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1073741824;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    ll a,b,c;
    cin >> a >> b >> c;

    //Use Sieve of Eratosthenes to precompute the largest divisor for all integers k, 1 <= k <= 1e6
    //The total divisors for an integer is (a+1)*(b+1)*(c+1)*... where a,b,c... are the exponents for
    //each prime divisor of that integer.
    //Precompute the total divisors for all integers k, 1 <= k <= 1e6
    //The answer is basically the summation of all the products from the three inputs
    vector<ll> maxs(1e6+1);
    vector<ll> divisors(1e6+1);
    for (int i = 2; i <= 1e6; i++){
        if (!maxs[i]){
            for (int j = i; j <= 1e6; j += i){
                maxs[j] = i;
            }
        }
    }
    for (int i = 1; i <= 1e6; i++){
        ll num = i;
        ll total = 1;
        while (num != 1){
            ll curr = 0;
            ll prime = maxs[num];
            while (!(num % prime)){
                num /= prime;
                curr++;
            }
            total *= curr + 1;
        }
        divisors[i] = total;
    }
    ll ans = 0;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            for (int k = 1; k <= c; k++){
               ans = (ans + divisors[i*j*k])%mod;
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}
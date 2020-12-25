#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Simulate the whole event for the given x
//Return a bool indicator to help the binary search
bool bisearch(ll n, ll k, ll m, ll x){
    ll g = 0;
    while (k > 0 && g < n){
        ll y = (n - g)/x;
        if (y < m){
            ll left = (n-g + m-1)/ m;
            return left <= k;
        }
        ll maxmatch = n - x*y;
        ll days = (maxmatch - g) / y + 1;
        days = min(days, k);
        g += y * days;
        k -= days;
    }
    return g >= n;
}

int main() {
    ofstream fout("loan.out");
    ifstream fin("loan.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    ll n, k, m;
    fin >> n >> k >> m;

    //Binary search to pin down the maximum possible x
    //that still satisfy the k days constraint
    ll a = 0;
    ll b = n;
    while (b-a>1){
        bool result = bisearch(n,k,m,(b+a)/2);
        if (result){
            a += (b-a)/2;
        }
        else{
            b -= (b-a)/2;
        }
    }
    if (!bisearch(n,k,m,b)) b = a;

    //Output
    fout << b;

    return 0;
}
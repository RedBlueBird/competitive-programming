#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Keep multiplying by 2 and mod 10^9+7 n times
    ll ans = 1;
    for (int i = 0; i < n; i++){
        ans = (ans*2)%1000000007;
    }

    //Output
    cout << ans;

    return 0;
}
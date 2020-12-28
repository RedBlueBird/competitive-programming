#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Greedily increase the moves by the maximum number currently seen
    int n;
    cin >> n;
    vector<ll> list(n);
    ll ans = 0;
    ll maxs = 0;
    for (int i = 0; i < n; i++){
        cin >> list[i];
        maxs = max(maxs, list[i]);
        if (i != 0){
            ans += maxs-list[i];
        }
    }

    //Output
    cout << ans;

    return 0;
}
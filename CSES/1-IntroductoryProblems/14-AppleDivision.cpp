#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<ll> nums(n);
    ll total = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        total += nums[i];
    }

    //Iterate through all the 2^n combinations
    //and find the one with minimum difference
    ll ans = INT_MAX;
    for (int i = 0; i < 1 << n; i++){
        ll sums = 0;
        for (int j = 0; j < n; j++){
            if (1 & (i>>j)) sums += nums[j];
        }
        ans = min(ans, abs(total-sums*2));
    }

    //Output
    cout << ans;

    return 0;
}
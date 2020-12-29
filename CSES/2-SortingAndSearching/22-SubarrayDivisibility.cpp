#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n,a;
    cin >> n;

    //For each occurrence of the same value after mod n, the counter plus 1
    //The answer will append its current amount of total occurrence each time it occur
    vector<int> nums(n, -1);
    nums[0] = 0;
    ll ans = 0, sums = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        sums = ((sums+a)%n+n)%n;
        ans += ++nums[sums];
    }

    //Output
    cout << ans;

    return 0;
}
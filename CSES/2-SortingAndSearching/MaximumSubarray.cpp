#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Processing the inputs while taking them
    ll ans;
    ll streak;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;
        if (!i) ans = a;
        streak = max(streak+a,a);
        ans = max(streak, ans);
    }

    //Output
    cout << ans;

    return 0;
}
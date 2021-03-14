#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<pll> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].ff >> points[i].ss;
    }
    sort(points.begin(), points.end());

    //Sweepline the sorted points
    //Only check the points left to the current point
    //Iff the absolute difference of x and y is less than the current minimum distance
    //Side node: don't use the ll(pow(long long,2)) function
    //           accuracy will decrease when test on very large numbers
    ll ans = LONG_LONG_MAX;
    int back = 0;
    set<pll> window;
    for (int i = 0; i < n; i++){
        ll bound = ceil(sqrt(ans));
        while (points[i].ff - points[back].ff >= bound){
            window.erase({points[back].ss, points[back].ff});
            back++;
        }
        auto it1 = window.lower_bound({points[i].ss-bound,points[i].ff});
        auto it2 = window.upper_bound({points[i].ss+bound,points[i].ff});
        for (auto it = it1; it != it2; it++){
            ll dx = points[i].ff-it->ss;
            ll dy = points[i].ss-it->ff;
            ans = min(ans, dx*dx+dy*dy);
        }
        window.insert({points[i].ss,points[i].ff});
    }

    //Output
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Iterate through all the jobs
    //Calculate the days it take to reach k-th job
    //Calculate the days it will take to reach goal with the current job
    //Take the one that require the minimum days
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        ll n, c;
        cin >> n >> c;
        vector<ll> earn(n);
        vector<ll> cost(n);
        for (int i = 0; i < n; i++){
            cin >> earn[i];
        }
        for (int i = 0; i < n-1; i++){
            cin >> cost[i];
        }
        ll curr = 0;
        ll days = 0;
        ll ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++){
            ans = min(ans, days + max(0ll, c - curr + earn[i] - 1)/earn[i]);
            ll duration = max(0ll, (cost[i]-curr + earn[i]-1))/earn[i];
            curr += duration * earn[i] - cost[i];
            days += duration + 1;
        }
        cout << ans << "\n";
    }


    return 0;
}
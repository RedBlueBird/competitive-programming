#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = int;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll k, m, n;
    cin >> k >> m >> n;

    vector<pair<ll, ll>> grassy_patches;
    vector<ll> nhoj;

    for (ll i = 0; i < k; i++) {
        ll p, t;
        cin >> p >> t;
        grassy_patches.push_back({p, t});
    }

    for (ll i = 0; i < m; i++) {
        ll f;
        cin >> f;
        nhoj.push_back(f);
    }

    sort(grassy_patches.begin(), grassy_patches.end());
    sort(nhoj.begin(), nhoj.end());

    vector<pair<ll, pair<ll, ll>>> intervals;
    for (auto grass : grassy_patches) {
        auto front = lower_bound(nhoj.begin(), nhoj.end(), grass.first);
        if (count(nhoj.begin(), nhoj.end(), *front) == 0) {
            intervals.push_back({grass.second, {nhoj[nhoj.size() - 1], grass.first + (grass.first - nhoj[nhoj.size() - 1])}});
        }
        else if (n < 100){
            if (nhoj[0] > grass.first) {
                intervals.push_back({grass.second, {grass.first, nhoj[0]}});
            } else {
                ll front_cow = nhoj[front - nhoj.begin()];
                ll back_cow = nhoj[front - nhoj.begin() - 1];
                ll closer = min(abs(grass.first - front_cow), abs(grass.first - back_cow));
                intervals.push_back({grass.second, {grass.first - closer, grass.first + closer}});
            }
        }
    }

//    for (auto interval : intervals) {
//        cout << interval.first << ": " << interval.second.first << ", " << interval.second.second << endl;
//    }

    if (n < 100){
        vector<ll> food;
        ll ending = intervals[0].second.second;
        ll counter = intervals[0].first;
        for (ll i = 1; i < intervals.size(); i++) {
            if (intervals[i].second.first >= ending) {
                food.push_back(counter);
                ending = intervals[i].second.second;
                counter = intervals[i].first;
            } else if (intervals[i].second.first < ending) {
                counter += intervals[i].first;
            }
            if (i == intervals.size() - 1) {
                food.push_back(counter);
            }
        }

        sort(food.begin(), food.end(), greater<ll>());
        ll answer = 0;
        for (int i = 0; i < n; i++) {
            answer += food[i];
        }
        cout << answer << endl;
    }
}
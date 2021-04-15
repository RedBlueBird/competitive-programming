#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//int main() {
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//
//    //Take Inputs
//    int t;
//    cin >> t;
//    while (t--){
//        int n;
//        cin >> n;
//        vector<pii> points(n);
//        for (int i = 0; i < n; i++)
//            cin >> points[i].ff;
//        for (int i = 0; i < n; i++)
//            cin >> points[i].ss;
//        sort(points.begin(), points.end());
//        ll ans = 0;
//        for (int i = 1; i < n; i++){
//            if (points[i].ff-points[i].ss == points[i-1].ff-points[i-1].ss){
//                if ((points[i-1].ff+points[i-1].ss)%2){
//                    ans += 0;
//                }else{
//                    ans += points[i].ff-points[i-1].ff;
//                }
//            }else{
//                ll x = points[i].ff-points[i-1].ff+1, y = points[i].ss-points[i-1].ss+1;
//                if ((points[i-1].ff+points[i-1].ss)%2){
//                    ans += (x-y+1)/2;
//                }else{
//                    ans += (x-y)/2;
//                }
//            }
//        }
//        cout << ans << "\n";
//    }
//
//
//    return 0;
//}

//<comment>
//Somehow (2,2) to (4,3) takes 1 energy when it should be 0
//Solution below uses the one in editorial
//https://codeforces.com/blog/entry/89007
//</comment>

bool isLeftArrow(int r, int c) {
    return (r + c) % 2 == 0;
}

bool isRightArrow(int r, int c) {
    return (r + c) % 2 == 1;
}

int calcDist(int r1, int c1, int r2, int c2) {
    if (r1 - c1 == r2 - c2) {
        return isRightArrow(r1, c1) ? 0 : r2 - r1;
    }
    r2 -= r1 - 1;
    c2 -= c1 - 1;
    if (isLeftArrow(r1, c1)) {
        return (r2 - c2) / 2;
    } else {
        return (r2 - c2 + 1) / 2;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<pair<int, int>> pts;
    for (int i = 0; i < n; i++) {
        pts.emplace_back(r[i], c[i]);
    }
    sort(pts.begin(), pts.end());
    int curR = 1, curC = 1;
    int res = 0;
    for (auto[nextR, nextC] : pts) {
        res += calcDist(curR, curC, nextR, nextC);
        curR = nextR;
        curC = nextC;
    }
    cout << res << "\n";
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
    int tests;
    cin >> tests;
    while (tests-- > 0) {
        solve();
    }
    return 0;
}
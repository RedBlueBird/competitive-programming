#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    set<pii> horz;
    set<pii> vert;
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        horz.insert(make_pair(a,b));
        vert.insert(make_pair(b,a));
    }

    //If there is at least one point that is above & below & left & right to the point
    //then increase the answer by 1
    //The way to check if such 4 points exists is using lower_bounds
    int ans = 0;
    for (auto i: horz){
        int a,b;
        tie(a,b) = i;
        auto hit = horz.lower_bound(make_pair(a,b));
        auto vit = vert.lower_bound(make_pair(b,a));
        if (hit != horz.begin() && (*prev(hit)).ff == a && hit != prev(horz.end()) && (*next(hit)).ff == a){
            if (vit != vert.begin() && (*prev(vit)).ff == b && vit != prev(vert.end()) && (*next(vit)).ff == b){
                ans++;
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}
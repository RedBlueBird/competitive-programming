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
    int n, m, r;
    cin >> n >> m >> r;
    vector<pii> ranges(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        ranges[i] = make_pair(a-r, a+r);
    }
    sort(ranges.begin(), ranges.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (ranges[i].ff > ranges[i-1].ss+1){
            ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
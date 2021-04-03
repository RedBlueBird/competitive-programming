#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

void debug(vector<ll>& a){
    for (int i = 0; i < a.size(); i++){
        cout << "(" << a[i] << "," << i << ")";
    }
    cout << "\n ------ \n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n+1);
    for (ll i = 1; i <= n; i++)
        cin >> nums[i];

    vector<ll> sums(n+2);
    vector<ll> maxs(n+2);
    vector<ll> psum(n+2);
    stack<pii> scan;
    for (ll i = n; i >= 1; i--){
        int len = 1;
        while (scan.size() && scan.top().ff <= nums[i]){
            sums[i] += (nums[i] - scan.top().ff) * scan.top().ss;
            len += scan.top().ss;
            scan.pop();
        }
        scan.push(make_pair(nums[i], len));
        sums[i] += sums[i+1];
        maxs[i] = max(maxs[i+1], nums[i]);
        psum[i] = nums[i] + psum[i+1];
    }
    debug(sums);
    debug(maxs);
    debug(psum);
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        cout << sums[a] - (maxs[a] * (n - b) - psum[b+1]) << "\n";
    }

    return 0;
}
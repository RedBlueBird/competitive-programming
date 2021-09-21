#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    ll ansMax = 0;
    ll currMax = 0;
    ll ansMin = nums[0];
    ll currMin = nums[0];
    for (int i = 0; i < n; i++){
        currMax = max(nums[i], currMax ^ nums[i]);
        ansMax = max(currMax, ansMax);
        if (i == 0) continue;
        currMin = min(nums[i], currMin ^ nums[i]);
        ansMin = min(currMin, ansMin);
    }

    cout << ansMax << " " << ansMin;

    return 0;
}
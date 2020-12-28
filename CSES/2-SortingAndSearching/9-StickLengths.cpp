#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    //The optimal cost is the sum of the difference of each value to the list's median
    sort(nums.begin(),nums.end());
    int median = n%2? nums[n/2] : (nums[n/2]+nums[n/2-1])/2;
    ll ans = 0;
    for (int i: nums){
        ans += abs(i-median);
    }

    //Output
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    //Keep track of the current subarray sum
    //If the next value exceed k, restart the subarray
    //If the total sum exceed k, reduce the sum by minus values from the front of the subarray
    //If the total sum equals k, append to the answer
    ll sums = 0;
    ll back = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (nums[i] > k){
            back = i+1;
            continue;
        }
        sums += nums[i];
        while (sums > k)
            sums -= nums[back++];
        if (sums == k) ans++;
    }

    //Output
    cout << ans;

    return 0;
}
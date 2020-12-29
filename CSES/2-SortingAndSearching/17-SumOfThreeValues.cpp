#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    //Just changing from 2sum to 3sum
    //Add another iteration to detect the 3rd number
    //If no 3-tuple numbers sum to k, return impossible
    map<int, pair<int,int>> pairs;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            pairs[nums[i]+nums[j]] = make_pair(i,j);
    for (int i = 0; i < n; i++)
        if (pairs.count(k-nums[i]) && pairs[k-nums[i]].first != i && pairs[k-nums[i]].second != i) {
            cout << pairs[k - nums[i]].first+1 << " " << pairs[k - nums[i]].second+1 << " " << i+1;
            return 0;
        }
    cout << "IMPOSSIBLE";

    return 0;
}
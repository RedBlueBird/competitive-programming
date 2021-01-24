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

    multiset<int> first;
    multiset<int> second;
    ll ans = 0;
    ll median;
    for (int i = 0; i < n; i++){
        if (first.empty() || *(--first.end()) >= nums[i]){
            first.insert(nums[i]);
            if (first.size()-1 > second.size()){
                second.insert(*(--first.end()));
                first.erase(--first.end());
            }
        } else {
            second.insert(nums[i]);
            if (first.size() < second.size()) {
                first.insert(*(second.begin()));
                second.erase(second.begin());
            }
        }
        if (i >= k){
            if (*(--first.end()) >= nums[i-k]){
                first.erase(first.find(nums[i-k]));
                if (first.size() < second.size()){
                    first.insert(*(second.begin()));
                    second.erase(second.begin());
                }
            } else if (*(second.begin()) <= nums[i-k]) {
                second.erase(second.find(nums[i-k]));
                if (first.size() > 1+second.size()) {
                    second.insert(*(--first.end()));
                    first.erase(--first.end());
                }
            }
        }
        median = *(--first.end());
        ans += abs(nums[i]-median);
        if (i +1 >= k)
            cout << ans << " ";
    }

    return 0;
}
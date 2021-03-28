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

    //Solution is the combination used in SlidingMedian and StickLength
    //Basically keep track of the total sum of the first set and second set
    //The sliding cost for each window is:
    //      (median*first_set_size - first_sum) + (second_sum - median*second_set_size)
    multiset<int> first;
    multiset<int> second;
    ll median = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++){
        if (first.empty() || *(--first.end()) >= nums[i]){
            sum1 += nums[i];
            first.insert(nums[i]);
            if (first.size()-1 > second.size()){
                sum2 += *(--first.end());
                sum1 -= *(--first.end());
                second.insert(*(--first.end()));
                first.erase(--first.end());
            }
        } else {
            sum2 += nums[i];
            second.insert(nums[i]);
            if (first.size() < second.size()) {
                sum1 += *(second.begin());
                sum2 -= *(second.begin());
                first.insert(*(second.begin()));
                second.erase(second.begin());
            }
        }
        if (i >= k){
            if (*(--first.end()) >= nums[i-k]){
                sum1 -= *first.find(nums[i-k]);
                first.erase(first.find(nums[i-k]));
                if (first.size() < second.size()){
                    sum1 += *(second.begin());
                    sum2 -= *(second.begin());
                    first.insert(*(second.begin()));
                    second.erase(second.begin());
                }
            } else if (*(second.begin()) <= nums[i-k]) {
                sum2 -= *second.find(nums[i-k]);
                second.erase(second.find(nums[i-k]));
                if (first.size() > 1+second.size()) {
                    sum2 += *(--first.end());
                    sum1 -= *(--first.end());
                    second.insert(*(--first.end()));
                    first.erase(--first.end());
                }
            }
        }
        median = *(--first.end());
        if (i +1 >= k)
            cout << median*first.size()-sum1 + sum2-median*second.size() << " ";
    }

    return 0;
}
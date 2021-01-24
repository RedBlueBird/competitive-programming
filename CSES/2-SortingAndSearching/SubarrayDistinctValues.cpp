#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //It is guaranteed all subsets with length k or below will exist
    //Now the job is to find all the subsets with length >k
    //Use a multiset to track all the seen numbers
    //A set to track the distinct numbers
    ll ans = (n*(n+1))/2 - ((n-k)*((n-k)+1))/2;
    multiset<int> track;
    set<int> window;
    int back = 0;
    for (int i = 0; i < n; i++){
        window.insert(nums[i]);
        track.insert(nums[i]);
        if (i - back < k) {
            continue;
        }
        while (int(window.size()) > k){
            track.erase(track.find(nums[back]));
            if (nums[back] != nums[back+1] && !track.count(nums[back])){
                window.erase(nums[back]);
            }
            back++;
        }
        ans += i - back - k + 1;
    }

    //Output
    cout << ans;

    return 0;
}
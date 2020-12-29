#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Binary search evaluator that determines the given max sum satisfies the condition or not
bool bisearch(vector<int>& nums, ll maxs, int k){
    ll groups = 1;
    ll sums = 0;
    for (int i = 0; i < nums.size(); i++){
        if  (sums + nums[i] > maxs){
            groups++;
            sums = nums[i];
        }
        else{
            sums += nums[i];
        }
    }
    if (groups > k) return false;
    return true;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    int highest = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        highest = max(highest, nums[i]);
    }

    //Binary search to obtain the maximum minimum sum
    ll a = highest, b = 1e18;
    while ((b-a)>1){
        if (bisearch(nums, (a+b)/2, k)){
            b -= (b-a)/2;
        } else{
            a += (b-a)/2;
        }
    }
    if (!bisearch(nums, a, k)) a = b;

    //Output
    cout << a;

    return 0;
}
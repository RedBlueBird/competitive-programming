#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //Let m be sum({x_1...x_k})
    //If {x_1...x_k} can form all integers <= m,
    //If x_k+1 <= m+1, then all the integers equal/below m+x_k+1 can be formed.
    //Else If x_k+1 > m+1, then all the integers equal/below m+x_k+1 exclude integers m+1 to x_k+1 - 1 can be formed
    sort(nums.begin(), nums.end());
    ll sums = 0;
    for (ll i: nums){
        if (i - sums > 1){
            cout << sums+1;
            return 0;
        }
        sums += i;
    }

    //Output this if all the positive integers <= sum(nums) can be formed
    cout << sums+1;

    return 0;
}
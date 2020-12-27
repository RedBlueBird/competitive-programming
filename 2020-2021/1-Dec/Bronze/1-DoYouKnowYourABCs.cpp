#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    //Take inputs
    int n = 7;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //Find the a b c
    sort(nums.begin(),nums.end());
    int a = nums[0];
    int b = nums[1];
    int c = nums.back()-a-b;

    //Output
    cout << a << " " << b << " " << c;

    return 0;
}
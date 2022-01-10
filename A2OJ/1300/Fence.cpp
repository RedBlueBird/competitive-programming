#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    //Perform rolling scan, store the sum of the consecutive k integers,
    //Then take away the integer k spots ago and add the new integer to the sum
    //The answer is the index of the smallest sum during the scan
    int n, k;
    cin >> n >> k;
    vector<int> nums(n+1);
    int ans = INT_MAX;
    int index = 0;
    int curr = 0;
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        curr += nums[i];
        if (i >= k){
            curr -= nums[i-k];
            if (ans > curr){
                ans = curr;
                index = i-k+1;
            }
        }
    }

    //Output
    cout << index;

    return 0;
}
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
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    //Iterate through all the numbers and find the one with minimal difference
    int ans = 1;
    int curr = INT_MAX;
    for (int i = 2; i <= n; i++){
        if (abs(nums[i] - nums[i-1]) < curr){
            curr = abs(nums[i] - nums[i-1]);
            ans = i;
        }
    }

    //Output
    if (abs(nums[n] - nums[1]) < curr){
        cout << 1 << " " << n;
    }else{
        cout << ans-1 << " " << ans;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    //Dp on bitmasks
    //Keep track of 2 values:
    //      total rides
    //      last ride's weight
    //For each subset of n, iterate over all the element in the subset
    //Compare the selected element to subset excluding the selected element
    //If the weight + curr_weight is over k, then total rides +1
    //Keep the minimum after all n iterations on the subset
    vector<pii> dp(1 << n);
    dp[0] = make_pair(1,0);
    for (int i = 1; i < (1<<n); i++){
        dp[i] = make_pair(n+1,0);
        for (int j = 0; j < n; j++){
            if (i&(1<<j)){
                pii curr = dp[i^(1<<j)];
                if (curr.ss + nums[j] <= k){
                    curr.ss += nums[j];
                }else{
                    curr.ff++;
                    curr.ss = nums[j];
                }
                dp[i] = min(dp[i], curr);
            }
        }
    }

    //Output
    cout << dp[(1 << n)-1].ff;

    return 0;
}
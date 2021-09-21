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
    vector<pii> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i].ff;
        nums[i].ss = i;
    }
    sort(nums.begin(), nums.end());

    //Reorder the sorted list
    //Such that the resulting list is the answer
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--){
        ans[nums[i].ss] = n-i;
        if (i != n-1 && nums[i].ff == nums[i+1].ff){
            ans[nums[i].ss] = ans[nums[i+1].ss];
        }
    }

    //Output
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}
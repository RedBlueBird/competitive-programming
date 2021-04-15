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
    //Order doesn't matter, sort the array first
    //The original array can be determined, by iterating the input array, setting the current number as the x
    //The rest will only be a possible original array if the sum of them equal to the value of the largest
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int n;
        cin >> n;
        n += 2;
        vector<ll> nums(n);
        ll total = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            total += nums[i];
        }
        sort(nums.begin(), nums.end());
        bool valid = false;
        for (int i = 0; i < n; i++){
            if ((i != n-1 && total - nums[i] - 2*nums[n-1] == 0) || (i == n-1 && total - nums[i] - 2*nums[n-2] == 0)){
                for (int j = 0; j < n; j++){
                    if (i == j) continue;
                    if ((i != n-1 && j == n-1) || (i == n-1 && j == n-2)) continue;
                    cout << nums[j] << " ";
                }
                cout << "\n";
                valid = true;
                break;
            }
        }
        if (!valid){
            cout << -1 << "\n";
        }
    }


    return 0;
}
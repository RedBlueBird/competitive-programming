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
    int k;
    cin >> k;
    vector<int> nums(12);
    for (int i = 0; i < 12; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    nums.push_back(0);

    //Greedily take the months with highest growth first
    //If the sum of all months are still not enough to reach k, output -1
    for (int i = 12; i >= 0; i--){
        k -= nums[i];
        if (k <= 0){
            cout << 12-i;
            return 0;
        }
    }
    cout << -1;

    return 0;
}
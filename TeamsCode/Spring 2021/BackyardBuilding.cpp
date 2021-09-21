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
    //Take the product of the two largest numbers in each query
    int n,m;
    cin >> n >> m;
    while (n--){
        vector<ll> nums(m);
        for (int i = 0; i < m; i++){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        cout << nums[m-2]*nums[m-1] << "\n";
    }

    return 0;
}
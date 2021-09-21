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
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //As long as all the numbers after k are the same
    //the answer is the n if all the numbers between n and k are the same as well
    for (int i = k+1; i < n; i++){
        if (nums[i] != nums[i-1]){
            cout << -1;
            return 0;
        }
    }
    for (int i = k-1; i >= 0; i--){
        if (nums[i] != nums[k]){
            cout << i+1;
            return 0;
        }
    }

    //Output
    cout << 0;
    return 0;
}
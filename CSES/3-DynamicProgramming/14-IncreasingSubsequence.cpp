#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, a;
    cin >> n;

    //dp[i] represent the increasing subsequence with length i with highest value dp[i]
    //If there is another value smaller than the previously seen value
    //set the index of that value to the newer smaller value
    vector<int> dp;
    for (int i = 0; i < n; i++){
        cin >> a;
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if (it == dp.end()){
            dp.push_back(a);
        }else{
            *it = a;
        }
    }

    //Output
    cout << dp.size();

    return 0;
}
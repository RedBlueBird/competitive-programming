#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    map<int,int> seen;

    //2sum problem
    //Using map to check
    //If answer has not been outputted after the whole iteration, return impossible
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        if (seen.count(k-nums[i])){
            cout << seen[k-nums[i]] << " " << i;
            return 0;
        }
        seen[nums[i]] = i;
    }
    cout << "IMPOSSIBLE";


    return 0;
}
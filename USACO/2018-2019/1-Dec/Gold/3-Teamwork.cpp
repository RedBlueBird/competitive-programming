#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("teamwork.out");
    ifstream fin("teamwork.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, k;
    fin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        fin >> nums[i];
    }

    //Simple dp, one of the rare self-explanatory ones
    vector<int> dp(n+1);
    for (int i = 1; i <= n; i++){
        int maxs = nums[i-1];
        for (int j = i; j >= max(1, i-k+1); j--){
            maxs = max(maxs, nums[j-1]);
            dp[i] = max(dp[i], maxs*(i-j+1) + dp[j-1]);
        }
    }

    //Output
    fout << dp[n];

    return 0;
}
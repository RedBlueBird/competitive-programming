#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
    ofstream fout("cbarn.out");
    ifstream fin("cbarn.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        fin >> nums[i];

    //Find left and right prefix-sums
    //Scan from left to right
    //The total steps can be computed by using the (i-1)'s result
    //subtract current left & right sums and add nums[i-1] * (n-1)
    //Keep the minimum value as the final answer.
    vector<int> rpsum(n+1);
    vector<int> lpsum(n+1);
    int curr = 0;
    for (int i = n-1; i >= 0; i--){
        rpsum[i] = nums[i] + rpsum[i+1];
        curr += nums[i] * i;
    }
    for (int i = 1; i <= n; i++){
        lpsum[i] = lpsum[i-1] + nums[i-1];
    }
    int ans = curr;
    for (int i = 1; i < n; i++){
        curr -= rpsum[i];
        curr += (n-1) * nums[i-1];
        curr -= lpsum[i-1];
        ans = min(ans, curr);
    }

    //Output
    fout << ans;

    return 0;
}


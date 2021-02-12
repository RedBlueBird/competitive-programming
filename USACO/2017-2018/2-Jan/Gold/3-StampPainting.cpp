#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

int main() {
    ofstream fout("spainting.out");
    ifstream fin("spainting.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    ll n,m,k;
    fin >> n >> m >> k;

    //Problem can be reduced to finding the total sequences that
    //length n, m different outcomes, some same outcome appear at least k times in a row
    //Answer: m^n - total sequences that is at most k-1 times in a row
    //O(NK): dp[i] += (m-1) * dp[i-j], for j < k
    //O(N): similar to above, but all the dp[i-j] don't need to be recalculated
    vector<ll> base(n+1,1);
    vector<ll> dp(n+1, m-1);
    for (int i = 1; i <= n; i++){
        base[i] = (base[i - 1] * m) % ll(1e9 + 7);
    }
    ll window = 0;
    for (int i = 1; i <= n; i++){
        if (i < k){
            dp[i] = base[i];
            window = (window + dp[i])%ll(1e9+7);
            continue;
        }
        dp[i] = (dp[i]*window)%ll(1e9+7);
        window -= dp[i-k+1];
        window = (window + dp[i])%ll(1e9+7);
    }

    //Output
    fout << (base[n] - dp[n] + ll(1e9+7))%ll(1e9+7);

    return 0;
}
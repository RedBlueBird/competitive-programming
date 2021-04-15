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

    //Precompute for all numbers within 1e7 the sum of its divisors
    //For each total sum, keep track the minimum number that has the total sum value
    vector<int> psum(1e7+1);
    vector<int> ans(1e7+1,-1);
    for (int i = 1; i <= 1e7; i++){
        for (int j = i; j <= 1e7; j += i)
            psum[j] += i;
        if (psum[i] <= 1e7 && ans[psum[i]] == -1)
            ans[psum[i]] = i;
    }

    //Take Inputs and output value according to the precomputation
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int c;
        cin >> c;
        cout << ans[c] << "\n";
    }


    return 0;
}
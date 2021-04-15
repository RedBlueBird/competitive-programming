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
    //Using greedy method to find a possible sequence length L-R+1 that have a sum of S
    //A value K from 1 to N is valid if the remaining sum after chosen K is equal or greater than the
    //minimum possible sum from the # of spots left
    //If during any process K goes negative, or the S is not reduced to 0, then it is not possible to form a sequence
    //Otherwise fill in the rest numbers with unused numbers.
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        vector<bool> used(n+1);
        vector<int> ans(n+1);
        int k = n;
        for (int i = l; i <= r; i++) {
            while (k > 0 && s - k < (r-i+1)*(r-i)/2)
                k--;
            if (k <= 0) break;
            ans[i] = k;
            s -= k;
            used[k] = true;
            if (i != r)
                k--;
        }
        if (k <= 0 || s != 0){
            cout << -1 << "\n";
            continue;
        }
        int back = 1;
        for (int i = 1; i <= n; i++){
            while (used[back]) back++;
            if (ans[i]) continue;
            used[back] = true;
            ans[i] = back;
        }
        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
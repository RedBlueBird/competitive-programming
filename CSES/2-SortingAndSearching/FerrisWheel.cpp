#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<int> child(n);
    for (int i = 0; i < n; i++){
        cin >> child[i];
    }

    //Pair the heaviest with the lightest
    //Keep greedily pairing them if possible
    sort(child.begin(), child.end());
    int back = 0;
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        if (child[i] + child[back] <= k) back++;
        ans++;
        if (i == back) break;
        if (i == back+1){
            ans++;
            break;
        }
    }

    //Output
    cout << ans;

    return 0;
}
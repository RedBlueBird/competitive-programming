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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = s[i];
        int a;
        cin >> a;
        ans[i] = ans[i-a];
    }

    //Output
    for (int i = 0; i < n; i++){
        cout << ans[i];
    }

    return 0;
}
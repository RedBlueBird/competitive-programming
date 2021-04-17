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

    //Process Inputs
    int n;
    string s;
    cin >> n >> s;

    //If there are k same colored stones in a row, then remove k-1 of them
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i-1])
            ans++;

    //Output
    cout << ans;

    return 0;
}
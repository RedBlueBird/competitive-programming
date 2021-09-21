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
    int n, m;
    cin >> n >> m;
    vector<int> pieces(m);
    for (int i = 0; i < m; i++)
        cin >> pieces[i];
    sort(pieces.begin(), pieces.end());

    //Iterate through the pieces and find the minimal difference
    int ans = INT_MAX;
    for (int i = 0; i <= m-n; i++){
        ans = min(ans, pieces[i+n-1]-pieces[i]);
    }

    //Output
    cout << ans;

    return 0;
}
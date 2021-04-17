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
    string a,b;
    cin >> a >> b;
    int n = a.size();

    //Output
    //Straight-forward character comparison
    for (int i = 0; i < n; i++){
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
        if (a[i] == b[i]) continue;
        if (int(a[i]) < int(b[i])){
            cout << -1;
            return 0;
        }
        cout << 1;
        return 0;
    }
    cout << 0;

    return 0;
}
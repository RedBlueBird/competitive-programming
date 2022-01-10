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
    int n,m, k;
    cin >> n >> m;
    int cmin = INT_MAX, cmax = 0, wmin = INT_MAX;
    for (int i = 0; i < n; i++){
        cin >> k;
        cmin = min(cmin, k);
        cmax = max(cmax, k);
    }
    for (int i = 0; i < m; i++){
        cin >> k;
        wmin = min(wmin, k);
    }

    //Output
    if (cmin * 2 < wmin && cmax < wmin){
        cout << max(cmax, cmin*2);
    }else{
        cout << -1;
    }

    return 0;
}
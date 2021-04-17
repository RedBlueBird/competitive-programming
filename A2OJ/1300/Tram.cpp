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
    cin >> n;

    //Find the minimum capacity
    int maxs = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        curr += b - a;
        maxs = max(curr, maxs);
    }

    //Output
    cout << maxs;

    return 0;
}
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
    int y, k, n;
    cin >> y >> k >> n;

    //Output all the multiples of k
    int c = 0;
    for (int i = (k - y%k) + y; i <= n; i += k){
        cout << i-y << " ";
        c++;
    }
    if (c == 0){
        cout << -1;
    }

    return 0;
}
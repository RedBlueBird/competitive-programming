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
    int n, a, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        sum += a;
    }

    //Find the number of possible finger counts Dima can show
    int ans = 0;
    for (int i = 1; i <= 5; i++){
        if ((sum + i)%(n+1) != 1)
            ans++;
    }

    //Output
    cout << ans;

    return 0;
}
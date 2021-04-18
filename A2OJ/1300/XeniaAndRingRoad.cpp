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
    //If the next house to visit is before the current one,
    //it means Xenia will have to travel clock-wise the whole ringroad before the destination
    ll n, m;
    cin >> n >> m;
    ll cycle = 0, back = 0;
    for (int i = 0; i < m; i++){
        ll a;
        cin >> a;
        if (a < back){
            cycle++;
        }
        back = a;
    }

    //Output
    cout << cycle*n + back - 1;

    return 0;
}
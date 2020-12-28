#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n;
    cin >> n;

    //Each k*k chessboard's total configurations can be determined
    //with the following formula
    for (ll i = 1; i <= n; i++){
        cout << (i*i*(i*i-1))/2 - 4*(i-1)*(i-2) << "\n";
    }

    return 0;
}
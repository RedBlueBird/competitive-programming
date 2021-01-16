#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs while also calculate the total sum
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n-1; i++){
        ll a;
        cin >> a;
        sum += a;
    }

    //The missing number is the total sum - calculated sum
    cout << (n+1)*n/2-sum;

    return 0;
}
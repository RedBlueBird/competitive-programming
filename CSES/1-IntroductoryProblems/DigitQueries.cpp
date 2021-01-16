#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Calculate and output the k-th digit while taking inputs
    for (int i = 0; i < n; i++){
        ll k;
        cin >> k;
        ll c = 9;
        ll it = 1;
        while (k > c*it){
            k -= c*it;
            c *= 10;
            it++;
        }

        ll ans = ((k-1)/it)+c/9;
        ll digit = (it - k%it)%it;
        while (digit--)
            ans /= 10;

        cout << ans%10 << "\n";
    }

    return 0;
}
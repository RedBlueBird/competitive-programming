#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Keep track of the total sum and the max number
    ll maxs = 0;
    ll sums = 0;
    for (int i = 0; i < n; i++){
        ll a;
        cin >> a;
        sums += a;
        maxs = max(maxs, a);
    }

    //The total time can be determined as follows
    //Since one person can only hold on to one book, we only need the first longest book
    if (maxs * 2 > sums)
        cout << maxs*2;
    else
        cout << sums;

    return 0;
}
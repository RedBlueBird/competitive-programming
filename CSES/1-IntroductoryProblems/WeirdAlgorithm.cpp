#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    ll n;
    cin >> n;
    cout << n << " ";

    //Keep divide or multiply with the said instructions in the problem until it hit 1
    //Output along the way
    while (n!=1){
        if (n % 2) n = n*3+1;
        else n = n/2;
        cout << n << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Taking inputs while outputting along the way
    //The pair will only be correct if their sum modular is divisible by 3
    //and the smaller one is no less than the 1/2 of the larger number
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if (b > a) swap(a,b);
        if ((a+b)%3 || b < a/2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
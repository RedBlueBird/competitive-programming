#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Total number of zeros are determined by the amount of fives
    //The problem can be interpreted as recycling 5 empty bottles for 1 brand new
    //and count the total possible bottles drank
    int ans = 0;
    while (n){
        n /= 5;
        ans += n;
    }

    //Output
    cout << ans;

    return 0;
}
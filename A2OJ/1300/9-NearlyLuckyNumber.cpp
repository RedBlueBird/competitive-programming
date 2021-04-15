#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    ll n;
    cin >> n;

    //Count the lucky digits
    int c = 0;
    while (n){
        if (n%10 == 4 || n%10 == 7)
            c++;
        n /= 10;
    }

    //Output
    if (c == 4 || c == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
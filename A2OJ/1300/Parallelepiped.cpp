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
    int x,y,z;
    cin >> x >> y >> z;

    //Calculate the distinct edges length
    int a,b,c;
    b = sqrt(x*y/z);
    a = x/b;
    c = y/b;

    //Output
    cout << (a+b+c)*4;

    return 0;
}
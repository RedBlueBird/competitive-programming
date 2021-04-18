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
    ll n, k;
    cin >> n >> k;

    //Output
    if (k > (n+1)/2){
        cout << (k - (n+1)/2)*2;
    }else{
        cout << k * 2 - 1;
    }

    return 0;
}
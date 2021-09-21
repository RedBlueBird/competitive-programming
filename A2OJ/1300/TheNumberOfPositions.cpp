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
    int n,a,b;
    cin >> n >> a >> b;

    //Output
    //Pretty straight-forward, can be done in O(1) time complexity with this formula
    cout << min(n-a, b+1);

    return 0;
}
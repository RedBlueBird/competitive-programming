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
    //Basic arithmetic, sum and divide
    int n,a;
    double total;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        total += a;
    }

    //Output
    cout << total/double(n);

    return 0;
}
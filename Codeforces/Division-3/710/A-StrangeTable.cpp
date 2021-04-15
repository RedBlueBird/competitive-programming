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

    //Take Inputs
    //Calculate the row and column the tile occupies in
    //Then calculate the number the tile should be counted as
    int t;
    cin >> t;
    for (int tests = 0; tests < t; tests++){
        ll n, m, x;
        cin >> n >> m >> x;
        x--;
        ll row = x%n, col = x/n+1;
        cout << row*m+col << "\n";
    }

    return 0;
}
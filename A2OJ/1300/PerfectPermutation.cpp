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
    int n;
    cin >> n;

    //If it is not possible to form then output -1
    if (n%2) {
        cout << -1;
        return 0;
    }

    //Output
    for (int i = 1; i <= n; i+=2){
        cout << i+1 << " " << i << " ";
    }

    return 0;
}
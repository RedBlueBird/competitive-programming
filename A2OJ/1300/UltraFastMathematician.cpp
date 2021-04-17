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
    string a,b;
    cin >> a >> b;

    //Straight-forward string comparison
    int n = a.size();
    for (int i = 0; i < n; i++){
        cout << int(a[i] != b[i]);
    }


    return 0;
}
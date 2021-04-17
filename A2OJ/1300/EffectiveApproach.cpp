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
    int n;
    cin >> n;
    vector<int> indices(n+1);
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        indices[a] = i;
    }

    //Finds the amount of operations it takes to find for each query
    int m;
    ll x = 0,y = 0;
    cin >> m;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        x += indices[a];
        y += n-indices[a]+1;
    }

    //Output
    cout << x << " " << y;

    return 0;
}
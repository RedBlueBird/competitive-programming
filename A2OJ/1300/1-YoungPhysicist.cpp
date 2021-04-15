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
    //As long as the sum is all 0 for all three axis
    //then it will be in equilibrium, otherwise it will not
    int n;
    cin >> n;
    int x = 0,y = 0,z = 0;
    for (int i = 0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        x += a; y += b; c += z;
    }

    //Output
    if (x == 0 && y == 0 && z == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
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
    int n, m;
    cin >> n >> m;

    //If two children require k turns fullfill their requirements, the one at the back go last
    //If one children require k more turns than another, the this children will be the one at back
    int curr = 0;
    int index = 1;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if ((a-1)/m >= curr) {
            curr = (a-1)/m;
            index = i;
        }
    }

    //Output
    cout << index;

    return 0;
}
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

    //Process Inputs and Output
    int n;
    cin >> n;
    while (n--){
        double a,b;
        cin >> a >> b;
        cout << setprecision(2) << fixed << ((b/a)-1)*100 << "\n";
    }


    return 0;
}
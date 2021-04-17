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
    int high = 0, hpos = INT_MAX, low = INT_MAX, lpos = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a > high){
            high = a;
            hpos = i;
        }
        if (a <= low){
            low = a;
            lpos = i;
        }
    }

    //Calculate the answer
    int ans = hpos + (n - lpos - 1);
    if (hpos > lpos) ans--;

    //Output
    cout << ans;

    return 0;
}
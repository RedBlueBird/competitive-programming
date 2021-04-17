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
    //Count the amount of numbers that are greater/lower than the all time highest/lowest
    int n;
    cin >> n;
    int ans = 0, mins = INT_MAX, maxs = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (mins > a){
            mins = a;
            if (i)
                ans++;
        }
        if (a > maxs){
            maxs = a;
            if (i)
                ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
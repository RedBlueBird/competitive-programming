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
    //Increase the answer by 1 if the number has already occurred once
    int ans;
    set<int> count;
    for (int i = 0; i < 4; i++){
        int a;
        cin >> a;
        if (count.count(a))
            ans++;
        count.insert(a);
    }

    //Output
    cout << ans;

    return 0;
}
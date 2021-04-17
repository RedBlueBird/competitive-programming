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

    //Keep track of the current value for X
    int curr = 0;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (s[1] == '+')
            curr++;
        else
            curr--;
    }

    //Output
    cout << curr;

    return 0;
}
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
    string s;
    cin >> s;

    //Straight-forward string processing
    string ans;
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] == '.'){
            ans += '0';
            continue;
        }
        if (s[i] == '-'){
            if (s[i+1] == '.')
                ans += '1';
            else
                ans += '2';
            i++;
        }
    }

    cout << ans;

    return 0;
}
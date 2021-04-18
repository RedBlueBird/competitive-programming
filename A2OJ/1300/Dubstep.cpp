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
    string s;
    cin >> s;
    int n = s.size();

    //If the next substring is "WUB", ignore it and insert ' ' if haven't already
    //Iterate through the whole string
    string ans = " ";
    for (int i = 0; i < n; i++){
        if (i < n-2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            if (ans.back() != ' ')
                ans += ' ';
            i += 2;
            continue;
        }
        ans += s[i];
    }
    ans.erase(ans.begin());
    if (ans.size() && ans.back() == ' ')
        ans.erase(prev(ans.end()));

    //Output
    cout << ans;

    return 0;
}
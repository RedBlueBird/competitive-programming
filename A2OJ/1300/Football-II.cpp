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

    //Check if any of the streaks in the string is >= 7
    int streak = 1;
    bool dangerous = false;
    for (int i = 1; i < n; i++){
        if (s[i-1] == s[i])
            streak++;
        else{
            streak = 1;
        }
        if (streak >= 7){
            dangerous = true;
        }
    }

    //Output
    if (dangerous)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
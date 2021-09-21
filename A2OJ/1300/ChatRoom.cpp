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

    //Check if the string contains the substring "hello" in it
    string og = "hello";
    int back = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == og[back])
            back++;
        if (back == 5) break;
    }

    //Output
    if (back == 5)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
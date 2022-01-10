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
    string a;
    cin >> a;

    //This is equivalent to remove the first zero in the bit-string
    bool removed = false;
    for (int i = 0; i < a.size(); i++){
        if ((a[i] == '0' && !removed) || (i == a.size()-1 && !removed)){
            removed = true;
            continue;
        }
        cout << a[i];
    }

    return 0;
}
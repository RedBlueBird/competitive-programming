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

    //Check if the given string is only consisted of the given numbers
    bool valid = true;
    for (int i = 0; i < n; i++){
        if (i < n-2 && s[i] == '1' && s[i+1] == '4' && s[i+2] == '4'){
            i += 2;
        }else if (i < n-1 && s[i] == '1' && s[i+1] == '4'){
            i += 1;
        }else if (s[i] != '1'){
            valid = false;
            break;
        }
    }

    //Output
    if (valid){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
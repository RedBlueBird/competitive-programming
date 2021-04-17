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
    int n = s.size();

    //Count the amount of letters that are uppercase
    int c = 0;
    for (int i = 0; i < n; i++){
        if (!islower(s[i])) c++;
    }

    //Convert and output
    if (c > n-c){
        for (int i = 0; i < n; i++){
            cout << (char)toupper(s[i]);
        }
    }else{
        for (int i = 0; i < n; i++){
            cout << (char)tolower(s[i]);
        }
    }

    return 0;
}
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

    //Count the distinct characters in a string
    set<char> distinct;
    int n = s.size();
    for (int i = 0; i < n; i++){
        distinct.insert(s[i]);
    }

    //Output
    if (distinct.size()%2){
        cout << "IGNORE HIM!";
    }else{
        cout << "CHAT WITH HER!";
    }

    return 0;
}
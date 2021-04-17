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
    map<char,int> count;
    for (int i = 0; i < 2; i++){
        string s;
        cin >> s;
        int n = s.size();
        for (int j = 0; j < n; j++){
            count[tolower(s[j])]++;
        }
    }
    string test;
    cin >> test;
    for (int i = 0; i < test.size(); i++){
        test[i] = tolower(test[i]);
        count[test[i]]--;
    }

    //Output
    for (auto i: count){
        if (i.ss != 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
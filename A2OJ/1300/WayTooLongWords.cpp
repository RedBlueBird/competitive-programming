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

    //Output each string following the abbreviation rules in the problem statement
    while (n--){
        string s;
        cin >> s;
        if (s.size() > 10){
            cout << s.front() << s.size()-2 << s.back() << "\n";
        }else{
            cout << s << "\n";
        }
    }

    return 0;
}
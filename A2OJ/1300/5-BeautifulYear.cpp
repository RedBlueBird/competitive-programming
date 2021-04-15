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
    int n;
    cin >> n;
    n++;

    //If all the digits are distinct, then output it
    while (1){
        int c = n;
        set<int> history;
        int len = 0;
        while (c){
            history.insert(c%10);
            c /= 10;
            len++;
        }
        if (history.size() == len){
            cout << n;
            break;
        }
        n++;
    }

    return 0;
}
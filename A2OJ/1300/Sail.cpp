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
    int n, p,q, x,y;
    cin >> n >> p >> q >> x >> y;
    string dir;
    cin >> dir;

    //Greedily follow only directions that will help the boat lead to the goal
    for (int i = 0; i < n; i++){
        if (dir[i] == 'S') {
            if (q > y) {
                q--;
            }
        }else if (dir[i] == 'N'){
            if (q < y){
                q++;
            }
        }else if (dir[i] == 'E'){
            if (p < x){
                p++;
            }
        }else if (dir[i] == 'W'){
            if (p > x){
                p--;
            }
        }
        if (p == x && q == y){
            cout << i+1;
            return 0;
        }
    }

    //Output
    cout << -1;

    return 0;
}
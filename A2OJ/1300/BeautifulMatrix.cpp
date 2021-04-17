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
    //Only record the position of where 1 occurred
    int x = 0, y = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int a;
            cin >> a;
            if (a == 1){
                x = i;
                y = j;
            }
        }
    }

    //Answer is the manhattan distance of 1 to (2,2) the center
    cout << abs(2-x) + abs(2-y);

    return 0;
}
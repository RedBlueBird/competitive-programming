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
    int x = 0, y = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a == 5){
            x++;
        }else{
            y++;
        }
    }

    //If the solution needs to be divisible by 90, then it has to be divisible by 10 first
    //and so it need to have at least one 0 digit
    if (x < 9 && y != 0){
        cout << 0;
        return 0;
    }else if (y == 0){
        cout << -1;
        return 0;
    }

    //Output
    //For a number with 5 to be divisible by 9, the sum of the digits needs to be divisible by 9
    //Since 5 and 9 are coprime, so the amount of 5 digits present must be divisible by 9
    for (int i = 0; i < (x/9)*9; i++){
        cout << 5;
    }
    for (int i = 0; i < y; i++){
        cout << 0;
    }

    return 0;
}
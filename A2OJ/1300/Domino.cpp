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
    int n, a, b;
    cin >> n;
    pii track;
    bool wild = false;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        track.ff += a;
        track.ss += b;
        if ((a+b)%2){
            wild = true;
        }
    }

    //Output
    //If the top and bottom row's sums parity are all even, no changes needed
    //If top and bottom sums have different parity, it is impossible to get both evens
    //If the sums parity are all odd, then as long as one domino have 1 odd 1 even number, it takes 1 move
    if (track.ff%2 ^ track.ss%2){
        cout << -1;
    }
    else if ((track.ff%2) && (track.ss%2)){
        if (wild){
            cout << 1;
        }else{
            cout << -1;
        }
    }
    else{
        cout << 0;
    }

    return 0;
}
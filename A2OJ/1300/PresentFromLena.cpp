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

    //Straight-forward number pattern rendering
    for (int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            int k = abs(i-n)+abs(j-n);
            if (k > n){
                cout << " ";
            }else{
                cout << n-k;
            }
            if (abs(i-n)+abs(j-n+1)>n && j >= n) break;
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
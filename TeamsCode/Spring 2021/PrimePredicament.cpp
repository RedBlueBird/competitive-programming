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
    //Prime factorize
    int n;
    cin >> n;
    int k = 2;
    while (n > 1){
        int count = 0;
        while (n > 1 && n%k == 0){
            n /= k;
            count++;
        }
        if (count)
            cout << k << " " << count << "\n";
        if (k == 2) k++;
        else k += 2;
    }


    return 0;
}
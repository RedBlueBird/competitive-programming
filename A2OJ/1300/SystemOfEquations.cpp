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
    int n, m;
    cin >> n >> m;

    //Bruteforce all the possible values for (a,b)
    //If the solution pair work, then increase answer by 1
    int ans = 0;
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= 1000; j++){
            if (i*i+j == n && i+j*j == m)
                ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
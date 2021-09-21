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
    vector<int> alice(n);
    vector<int> bob(n);
    for (int i = 0; i < n; i++){
        cin >> alice[i];
    }
    for (int i = 0; i < n; i++){
        cin >> bob[i];
    }
    sort(bob.begin(), bob.end());
    sort(alice.begin(), alice.end());

    //Greedily sort and compare
    int back = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (alice[i] > bob[back]){
            ans++;
            back++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
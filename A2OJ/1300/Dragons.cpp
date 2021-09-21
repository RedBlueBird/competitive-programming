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
    int s,n;
    cin >> s >> n;
    vector<pii> dragons(n);
    for (int i = 0; i < n; i++){
        cin >> dragons[i].ff >> dragons[i].ss;
    }
    sort(dragons.begin(), dragons.end());

    //Greedily start dueling from the weakest dragon to the strongest
    bool survive = true;
    for (int i = 0; i < n; i++){
        if (s > dragons[i].ff){
            s += dragons[i].ss;
        }else{
            survive = false;
            break;
        }
    }

    //Output
    if (survive)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
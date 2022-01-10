#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //Process Inputs
    //If the card number has already been seen, it will be made into a pair
    int n, k;
    cin >> n;
    map<int,int> see;
    vector<pii> ans;
    for (int i = 1; i <= 2*n; i++){
        cin >> k;
        if (!see.count(k)){
            see[k] = i;
        }else{
            ans.push_back(make_pair(see[k], i));
            see.erase(see.find(k));
        }
    }

    //Output
    //If there are still unmatched cards, output -1
    if (see.size()){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].ff << " " << ans[i].ss << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n, k;
    cin >> n >> k;
    set<int> cows = {-1};
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        cows.insert(a/12);
    }

    //Divide the input by 12
    //Sort their difference from large to small
    //Compute the maximum time with only 1 jump
    //Decrease the time by subtract jumps-1 gaps from the difference array
    int ans = *cows.rbegin()+1;
    vector<int> diff;
    for (auto i = cows.begin(); i != prev(cows.end()); i++){
        diff.push_back(*next(i)-*i-1);
    }
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < k-1; i++){
        ans -= diff[i];
    }

    //Output
    cout << ans*12;

    return 0;
}
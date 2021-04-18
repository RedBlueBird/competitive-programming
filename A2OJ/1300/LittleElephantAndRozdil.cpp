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

    //Iterate through all the numbers, keep track the minimum number
    //If there are multiple minimums, set the answer to -1
    int ans = -1;
    int curr = INT_MAX;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if (a == curr){
            ans = -1;
        }
        if (a < curr){
            curr = a;
            ans = i;
        }
    }

    //Output
    if (ans == -1){
        cout << "Still Rozdil";
    }else{
        cout << ans;
    }

    return 0;
}
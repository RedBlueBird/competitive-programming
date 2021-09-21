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

    //Keep track of the highest/lowest number in the list and their occurrence.
    int mins = INT_MAX;
    ll micount = 0;
    int maxs = 0;
    ll macount = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (mins >= a){
            if (mins == a){
                micount++;
            }else{
                micount = 1;
            }
            mins = a;
        }
        if (maxs <= a){
            if (maxs == a){
                macount++;
            }else{
                macount = 1;
            }
            maxs = a;
        }
    }

    //Output
    if (maxs == mins){
        cout << 0 << " " << micount*(micount-1)/2;
    }else{
        cout << maxs-mins << " " << micount * macount;
    }

    return 0;
}
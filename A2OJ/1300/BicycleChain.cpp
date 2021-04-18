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
    vector<int> former(n);
    for (int i = 0; i < n; i++)
        cin >> former[i];
    int m;
    cin >> m;
    vector<int> latter(m);
    for (int i = 0; i < m; i++)
        cin >> latter[i];

    //Iterate through all the possible pairs
    //Keep track the highest "integer" ratio
    //Count the pairs with highest ratio for answer
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (latter[i]%former[j] == 0){
                if (latter[i]/former[j] == curr){
                    ans++;
                }
                else if (latter[i]/former[j] > curr){
                    curr = latter[i]/former[j];
                    ans = 1;
                }
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}
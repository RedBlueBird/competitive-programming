#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;

    //Perform a swap if the first character is B and second is G
    while (t--){
        for (int i = 0; i < n-1; i++){
            if (s[i] == 'B' && s[i+1] == 'G'){
                swap(s[i],s[i+1]);
                i++;
            }
        }
    }

    //Output
    cout << s;

    return 0;
}
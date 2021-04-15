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

    //Take Inputs
    //Greedily only convert if the previous conversion index to index + k,
    //The current index is the latest possible
    int t;
    cin >> t;
    for (int test = 0; test < t; test++){
        int n, k;
        string s;
        cin >> n >> k >> s;
        stack<int> ans;
        for (int i = 0; i < n; i++){
            if (s[i] == '*'){
                if (ans.size() > 1){
                    int prev = ans.top(); ans.pop();
                    if (i-ans.top() > k){
                        ans.push(prev);
                    }
                }
                ans.push(i);
            }
        }
        cout << ans.size() << "\n";
    }


    return 0;
}
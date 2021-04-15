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
    //Iterate through the string
    //As long as the answer string's last character is lexicographically smaller than the current
    //and it occurs after the current also, removes it
    //This greedy approach allows us to construct the lexicographically maximum unique string guaranteed
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> count(26);
        vector<bool> used(26);
        for (int i = 0; i < n; i++){
            count[int(s[i]-'a')]++;
        }
        string ans;
        for (int i = 0; i < n; i++){
            count[int(s[i]-'a')]--;
            if (used[int(s[i]-'a')]) continue;
            while (ans.size() && ans.back() < s[i] && count[int(ans.back()-'a')]){
                used[int(ans.back()-'a')] = false;
                ans.pop_back();
            }
            ans += s[i];
            used[int(s[i]-'a')] = true;
        }
        cout << ans << "\n";
    }


    return 0;
}
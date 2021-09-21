#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Check if a substring is a palindrome
bool check(string& s, int start, int end){
    int n = s.size();
    for (int i = start; i <= start+(end-start)/2; i++){
        if (s[i] != s[end-(i-start)])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;

    //Iterate through each string, check if it is possible to form a
    //palindrome on each end
    int ans = 0;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int len = s.size();
        for (int j = 0; j < len-1; j++){
            if (check(s, 0, j) && check(s, j+1, len-1)){
                ans++;
                break;
            }
        }
    }

    //Output
    cout << ans;

    return 0;
}
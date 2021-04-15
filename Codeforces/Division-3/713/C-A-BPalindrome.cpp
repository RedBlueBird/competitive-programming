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
    //If s[k] is not unknown, then s[n-k-1] must also be s[k]
    //If they are different then -1
    //If both are unknown, then set them both to 0 or 1 depend on how much a or b left
    //if k is the middle of s, then only subtraction of 1 instead 2 is needed
    //If after any of those operations a or b reach negative, then -1
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int a,b,n;
        cin >> a >> b;
        string s;
        cin >> s;
        n = s.size();
        queue<int> track;
        for (int i = 0; i < (n+1)/2; i++){
            if (s[i] != s[n-i-1] && s[i] != '?' && s[n-i-1] != '?'){
                a = -1;
                break;
            }
            if (s[i] == '0' || s[n-i-1] == '0'){
                s[i] = '0';
                s[n-i-1] = '0';
                a -= 2;
                if (i == (n+1)/2-1 && n%2) a++;
            }else if (s[i] == '1' || s[n-i-1] == '1'){
                s[i] = '1';
                s[n-i-1] = '1';
                b -= 2;
                if (i == (n+1)/2-1 && n%2) b++;
            }else{
                track.push(i);
            }
        }
        while (track.size()){
            if (!(track.front() == (n+1)/2-1 && n%2)){
                if (a > 1) {
                    s[track.front()] = '0';
                    s[n - track.front() - 1] = '0';
                    a -= 2;
                }else if (b > 1){
                    s[track.front()] = '1';
                    s[n - track.front() - 1] = '1';
                    b -= 2;
                }else{
                    a = -1;
                    break;
                }
            }else{
                if (a == 1){
                    s[track.front()] = '0';
                    a--;
                }else if (b == 1){
                    s[track.front()] = '1';
                    b--;
                }
            }
            track.pop();
        }
        if (a != 0 || b != 0){
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++){
            cout << s[i];
        }
        cout << "\n";
    }

    return 0;
}
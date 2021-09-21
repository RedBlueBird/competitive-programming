#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

char vowels[] = {'a','e','i','o','u','y'};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    string s;
    cin >> s;
    int n = s.size();

    //Process the input string exactly like the question asked to
    string ans = "";
    for (int i = 0; i < n; i++){
        s[i] = tolower(s[i]);
        bool consonant = true;
        for (int j = 0; j < 6; j++){
            if (s[i] == vowels[j]){
                consonant = false;
                break;
            }
        }
        if (!consonant) continue;
        ans += '.';
        ans += s[i];
    }

    //Output
    cout << ans;

    return 0;
}
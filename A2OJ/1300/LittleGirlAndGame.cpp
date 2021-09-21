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
    string letters;
    cin >> letters;
    int n = letters.size();

    //Count the letters that occurred odd amount of time
    vector<int> count(26);
    for (int i = 0; i < n; i++){
        count[int(letters[i]-'a')]++;
    }
    int total = 0;
    for (int i = 0; i < 26; i++){
        if (count[i]%2) total++;
    }

    //Output
    //If there is no odd occurrence, then first player win
    //If there is odd amount of odds, then first player win,
    //otherwise second player win
    if (total%2 || total == 0){
        cout << "First";
    }else{
        cout << "Second";
    }

    return 0;
}
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
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();

    //Count the occurrence of each character in the string
    //If the count is not divisible by k, return -1;
    map<char,int> count;
    for (int i = 0; i < n; i++){
        count[s[i]]++;
    }
    for (auto i: count){
        if (i.ss%k){
            cout << -1;
            return 0;
        }
    }

    //Output
    for (int i = 0; i < k; i++){
        for (auto i: count){
            for (int j = 0; j < i.ss/k; j++) {
                cout << i.ff;
            }
        }
    }

    return 0;
}
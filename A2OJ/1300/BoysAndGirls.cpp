#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //Process Inputs
    int n, m;
    cin >> n >> m;

    //Greedily generate pairs of boy & girl until one of them ran out
    //then output the rest of boy/girl
    for (int i = 0; i < min(n,m); i++){
        if (n >= m){
            cout << "BG";
        }else{
            cout << "GB";
        }
    }
    for (int i = max(n,m)-min(n,m); i > 0; i--){
        if (n > m){
            cout << "B";
        }else{
            cout << "G";
        }
    }

    return 0;
}
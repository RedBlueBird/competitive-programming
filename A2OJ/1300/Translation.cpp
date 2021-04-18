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
    string a,b;
    cin >> a >> b;
    int n = a.size();

    //Check if two strings are reverse of each other
    bool valid = true;
    for (int i = 0; i < n; i++){
        if (a[i] != b[n-i-1]){
            valid = false;
            break;
        }
    }

    //Output
    if (valid){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}
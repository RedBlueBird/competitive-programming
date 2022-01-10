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
    int n,m;
    cin >> a >> b;
    n = a.size(); m = b.size();

    //Output mismatched letters between the two strings
    vector<int> errors;
    if (n != m){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            errors.push_back(i);
        }
    }

    //Output
    if (errors.size() != 2){
        cout << "NO";
        return 0;
    }
    if (a[errors[0]] == b[errors[1]] && a[errors[1]] == b[errors[0]]){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;

    return 0;
}
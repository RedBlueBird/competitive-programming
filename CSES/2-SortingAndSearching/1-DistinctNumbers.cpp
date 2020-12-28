#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    set<int> raw;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        raw.insert(a);
    }

    //Output
    cout << raw.size();

    return 0;
}
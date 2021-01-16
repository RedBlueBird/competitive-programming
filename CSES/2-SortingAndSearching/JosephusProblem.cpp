#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    vector<int> pointer(n);
    for (int i = 0; i < n; i++)
        pointer[i] = (i+1)%n;
    int removed = 0;
    int curr = 0;
    while (removed < n){
        int next = pointer[curr];
        pointer[curr] = pointer[next];
        cout << next+1 << " ";
        curr = pointer[next];
        removed++;
    }

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //It is guaranteed there will be no solution when 1 < n < 4
    if (n < 4 && n > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    //Otherwise simply output all the evens first and odds next
    for (int i = 1; i < n; i+=2){
        cout << i+1 << " ";
    }
    for (int i = 0; i < n; i+=2){
        cout << i+1 << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, a;
    cin >> n;

    //Using a stack to keep track of the most recent smaller integers
    //Taking input and output along the way
    stack<pair<int,int>> nsv;
    for (int i = 1; i <= n; i++){
        cin >> a;
        while (!nsv.empty() && nsv.top().first >= a) nsv.pop();
        if (nsv.empty()) cout << 0 << " ";
        else cout << nsv.top().second << " ";
        nsv.push(make_pair(a, i));
    }


    return 0;
}
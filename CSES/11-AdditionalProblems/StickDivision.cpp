#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    priority_queue<int> sticks;
    for (int i = 0; i < k; i++){
        int a;
        cin >> a;
        sticks.push(-a);
    }

    //Greedily take the two sticks with minimum size
    //and then combine them
    ll ans = 0;
    while (sticks.size()>1){
        int a = sticks.top(); sticks.pop();
        int b = sticks.top(); sticks.pop();
        ans += -1*(a+b);
        sticks.push(a+b);
    }

    //Output
    cout << ans;

    return 0;
}
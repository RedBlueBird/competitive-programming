#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m;
    cin >> n >> m;
    vector<int> presum(n+1);
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        presum[i] = presum[i-1]^a;
    }

    //Similar to prefix sum, this is prefix xor sum
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        cout << int(presum[b] ^ presum[a-1]) << "\n";
    }

    return 0;
}
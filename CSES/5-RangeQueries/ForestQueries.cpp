#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Compute the prefix sum matrix while taking the inputs
    int n, m;
    cin >> n >> m;
    vector<vector<int>> presum(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++){
        string a;
        cin >> a;
        for (int j = 1; j <= n; j++){
            presum[i][j] += presum[i][j-1] + presum[i-1][j] - presum[i-1][j-1];
            if (a[j-1] == '*'){
                presum[i][j]++;
            }
        }
    }

    //This is just a prefix sum but in 2d instead
    //Code should be self-explanatory on this one
    for (int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << presum[c][d] - presum[c][b-1] - presum[a-1][d] + presum[a-1][b-1] << "\n";
    }

    return 0;
}
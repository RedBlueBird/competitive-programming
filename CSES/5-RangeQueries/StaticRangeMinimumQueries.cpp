#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n,m;
    cin >> n >> m;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    //Precompute the value of log for numbers up to n
    //Construct sparse table using dp
    //This data structure is more efficient with static minimum query than segment tree
    vector<int> log(n+1);
    for (int i = 2; i <= n; i++){
        log[i] = log[i/2]+1;
    }
    vector<vector<int>> sparse(n+1, vector<int>(log[n]+1));
    for (int i = 0; i <= n; i++){
        sparse[i][0] = nums[i];
    }
    for (int j = 1; j <= log[n]; j++){
        for (int i = 0; i + (1 << j) <= n+1; i++){
            sparse[i][j] = min(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }

    //Output the answer for each query in O(1) time
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        int k = log[b-a+1];
        cout << min(sparse[a][k],sparse[b - (1<<k) + 1][k]) << "\n";
    }

    return 0;
}
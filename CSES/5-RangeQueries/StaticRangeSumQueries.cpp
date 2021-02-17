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
    //Construct prefix-sum
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n+1);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        nums[i] += nums[i-1];
    }

    //Output the difference between each values
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        cout << nums[b]-nums[a-1] << "\n";
    }

    return 0;
}
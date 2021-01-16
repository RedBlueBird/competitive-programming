#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n,a;
    cin >> n;

    vector<bool> nums(n+1);
    int count = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (!nums[a-1]){
            count++;
        }
        nums[a] = true;
    }

    //Output
    cout << count;

    return 0;
}
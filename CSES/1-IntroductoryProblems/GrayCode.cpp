#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Permutate through all the possible bit combinations
    vector<int> ans = {0,1};
    for (int i = 1; i < n; i++){
        int k = pow(2,i);
        for (int j = k-1; j >= 0; j--){
            ans.push_back(ans[j]+(1<<(i)));
        }
    }

    //Output the integers in a bit string format
    int cache[n];
    for (int i: ans){
        int k = i;
        for (int j = 0; j < n; j++){
            cache[n-j-1] = k%2;
            k /= 2;
        }
        for (int j: cache){
            cout << j;
        }
        cout << "\n";
    }

    return 0;
}
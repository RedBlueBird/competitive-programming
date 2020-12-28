#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    //Greedily assign the cubes to previous towers if possible
    multiset<int> nums;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        auto it = nums.upper_bound(a);
        if (it!=nums.end()){
            nums.erase(it);
        }
        nums.insert(a);
    }

    //Output
    cout << nums.size();

    return 0;
}
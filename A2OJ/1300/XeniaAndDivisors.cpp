#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    vector<int> nums(8);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        nums[k]++;
    }

    //Tedious checks to make sure the input is possible to be tupled in 3
    if (nums[1] != n/3 || nums[5] || nums[7]){
        cout << -1;
        return 0;
    }
    if ((nums[2] + nums[3] != nums[4] + nums[6])){
        cout << -1;
        return 0;
    }
    if (nums[6] < nums[3] || nums[2]-(nums[6]-nums[3]) < 0 || nums[2]-(nums[6]-nums[3]) != nums[4]){
        cout << -1;
        return 0;
    }

    //For a valid list of tuples, there exists only 1 solution
    //Output
    for (int i = 0; i < nums[3]; i++){
        cout << 1 << " " << 3 << " " << 6 << "\n";
    }
    for (int i = 0; i < nums[6]-nums[3]; i++){
        cout << 1 << " " << 2 << " " << 6 << "\n";
    }
    for (int i = 0; i < nums[2]-(nums[6]-nums[3]); i++){
        cout << 1 << " " << 2 << " " << 4 << "\n";
    }

    return 0;
}
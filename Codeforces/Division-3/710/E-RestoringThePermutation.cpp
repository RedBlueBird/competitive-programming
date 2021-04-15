#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //If the current maximum changes, then the original value at that index will guaranteed to be that new value
    //Otherwise, greedily only take the smallest or largest element remain from the set
    int test;
    cin >> test;
    for (int t = 0; t < test; t++){
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }
        set<int> remainlow, remainhigh;
        for (int i = 1; i <= n; i++) {
            remainlow.insert(i);
            remainhigh.insert(-i);
        }
        vector<int> mins(n), maxs(n);
        int high = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] > high){
                high = nums[i];
                mins[i] = high;
                maxs[i] = high;
                remainlow.erase(high);
                remainhigh.erase(-high);
            }else{
                mins[i] = *remainlow.begin();
                remainlow.erase(remainlow.begin());
                maxs[i] = -*remainhigh.upper_bound(-high);
                remainhigh.erase(remainhigh.upper_bound(-high));
            }
        }
        for (int i = 0; i < n; i++){
            cout << mins[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++){
            cout << maxs[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
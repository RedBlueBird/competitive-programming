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
    //Straight-forward, find the unique number, get the index
    int t;
    cin >> t;
    for (int test = 0; test < t; test++){
        int n;
        cin >> n;
        map<int,int> history;
        vector<int> nums(n);
        for (int i = 0; i < n; i++){
            cin >> nums[i];
            history[nums[i]]++;
        }
        int num = 0;
        for (auto i: history){
            if (i.ss == 1) {
                num = i.ff;
                break;
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i] == num){
                cout << i+1 << "\n";
                break;
            }
        }
    }

    return 0;
}
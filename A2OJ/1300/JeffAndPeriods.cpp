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
    map<int,vector<int>> track;
    vector<pii> ans;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        track[nums[i]].push_back(i);
    }

    //For each number, keep track of all the index it occurred in
    //If the indices form arithmetic sequence, then append it to the answer
    for (auto i: track){
        bool valid = true;
        int diff = 0;
        if (track[i.ff].size() == 2){
            diff = track[i.ff][1] - track[i.ff][0];
        }
        for (int j = 2; j < track[i.ff].size(); j++){
            diff = track[i.ff][j] - track[i.ff][j-1];
            if (track[i.ff][j-1]-track[i.ff][j-2] != track[i.ff][j]-track[i.ff][j-1]){
                valid = false;
                break;
            }
        }
        if (valid){
            ans.push_back(make_pair(i.first, diff));
        }
    }

    //Output
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].ff << " " << ans[i].ss << "\n";
    }

    return 0;
}
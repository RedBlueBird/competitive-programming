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
    string s;
    cin >> s;

    //Use regex to remove the + sign and sort the input numbers
    regex re("[0-9]+|[^+]");
    smatch res;
    auto start = s.cbegin();
    vector<int> ans;
    while (regex_search(start, s.cend(), res, re)){
        ans.push_back(stoi(res[0]));
        start = res.suffix().ff;
    }
    sort(ans.begin(), ans.end());

    //Output
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if (i != ans.size()-1)
            cout << "+";
    }

    return 0;
}
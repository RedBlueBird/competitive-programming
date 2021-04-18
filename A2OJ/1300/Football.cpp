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

    //For each team's appearance, increase their team score count by 1
    //Then iterate through all the teams and the one with highest score is the answer
    set<pair<string,int>> log = {{"~",0}};
    for (int i = 0; i < n; i++){
        string a;
        cin >> a;
        auto it = log.lower_bound(make_pair(a,0));
        if ((*it).ff == a){
            log.insert(make_pair(a,(*it).ss+1));
            log.erase(it);
        }else{
            log.insert(make_pair(a,1));
        }
    }
    string ans = "~";
    int curr = 0;
    for (auto i: log){
        if (i.ss > curr){
            curr = i.ss;
            ans = i.ff;
        }
    }

    //Output
    cout << ans;

    return 0;
}
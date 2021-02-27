#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ofstream fout("hayfeast.out");
    ifstream fin("hayfeast.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    ll k;
    fin >> n >> k;
    vector<pii> nums(n);
    for (int i = 0; i < n; i++){
        fin >> nums[i].ff >> nums[i].ss;
    }

    //Can be solved through sliding window minimum method
    //As long as the spiciness fullfills the requirement,
    //check if the current maximum is lower than the answer
    ll ans = LONG_LONG_MAX;
    deque<pii> window;
    ll curr = 0;
    int back = -1;
    int front = 0;
    while (front < n) {
        while (front < n && curr < k) {
            curr += nums[front].ff;
            while (window.size() && window.back().ff <= nums[front].ss) {
                window.pop_back();
            }
            window.push_back(make_pair(nums[front].ss, front));
            front++;
        }
        ans = min(ans, window.front().ff);
        back++;
        curr -= nums[back].ff;
        if (window.size() && window.front().ss == back)
            window.pop_front();
    }

    //Ouput
    fout << ans;

    return 0;
}


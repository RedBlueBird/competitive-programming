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
    int n, k;
    cin >> n >> k;
    string lists;
    cin >> lists;
    lists += 'x';
    vector<pii> marbles = {{0,lists[0]=='B'}};
    for (int i = 0; i < n; i++){
        marbles.back().ff++;
        if (lists[i] != lists[i+1]){
            marbles.push_back({0,lists[i+1]=='B'});
        }
    }
    marbles.pop_back();

    int ans = 0;
    int curr = 0;
    int power = k;
    int indexleft = 0;
    n = marbles.size();
    while (true){
        if (marbles[indexleft].ss){
            if (power < marbles[indexleft].ff) break;
            power -= marbles[indexleft].ff;
        }
        else{
            curr += marbles[indexleft].ff;
        }
        indexleft++;
    }
    int indexright = n-1;
    while (true){
        while (true){
            if (marbles[indexright].ss){
                if (power < marbles[indexright].ff) break;
                power -= marbles[indexright].ff;
            }
            else{
                curr += marbles[indexright].ff;
            }
            indexright--;
        }
        ans = max(curr, ans);
        if (indexleft < 2) break;
        curr -= marbles[indexleft-1].ff;
        power += marbles[indexleft-2].ff;
        indexleft -= 2;
    }

    //Output
    cout << ans;

    return 0;
}
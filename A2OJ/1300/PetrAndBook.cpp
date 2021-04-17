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
    vector<pii> pages(8);
    for (int i = 1; i <= 7; i++){
        int a;
        cin >> a;
        pages[i] = make_pair(pages[i-1].ff+a, i);
    }

    //Find the amount of whole weeks it take to finish the pages
    int cycle = (n-1)/pages[7].ff;
    n -= cycle * pages[7].ff;

    //Find the day of the week that finishes the remaining pages
    cout << (*lower_bound(pages.begin(), pages.end(), make_pair(n,0))).ss;

    return 0;
}
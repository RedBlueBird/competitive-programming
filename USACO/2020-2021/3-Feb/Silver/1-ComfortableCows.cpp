#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;

    vector<int> horz(1001);
    vector<int> vert(1001);
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        horz[a]++;
        vert[b]++;
        int ans = 0;
        for (int j: horz)
            if (j == 3)
                ans++;
        for (int j: vert)
            if (j == 3)
                ans++;
        cout << ans << "\n";
    }


    return 0;
}
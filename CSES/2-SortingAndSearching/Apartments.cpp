#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apps(n);
    vector<int> houses(m);
    for (int i = 0; i < n; i++){
        cin >> apps[i];
    }
    for (int i = 0; i < m; i++){
        cin >> houses[i];
    }

    //Sort the applicants
    //Assign them a house if possible greedily
    sort(apps.begin(),apps.end());
    sort(houses.begin(),houses.end());
    int c = 0;
    int ans = 0;
    for (int i = 0; i < m; i++){
        while (c<n && apps[c]+k<houses[i]) c++;
        if (c == n) break;
        if (houses[i]>=apps[c]-k && houses[i]<=apps[c]+k){
            ans++;
            c++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
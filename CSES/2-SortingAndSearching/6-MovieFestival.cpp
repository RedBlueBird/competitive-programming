#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Sort two pairs of int by their second value
bool cmp(const pair<int,int> a, const pair<int,int> b){
    return a.second < b.second;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].first >> movies[i].second;

    //Sort and then greedily take the movie that always end the earliest
    sort(movies.begin(), movies.end(), cmp);
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; i++){
        if (movies[i].first >= curr){
            ans++;
            curr = movies[i].second;
        }
    }

    //Output
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(const pair<int,int> a, const pair<int,int> b){
    return a.second < b.second;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), cmp);
    int ans = 0;
    int curr = k;
    priority_queue<int> watching;
    for (int i = 0; i < n; i++){
        if (!watching.empty() && watching.top()*-1 < movies[i].first){
            watching.pop();
            watching.push(movies[i].second*-1);
            ans++;
        }
        else if (curr){
            curr--;
            watching.push(movies[i].second*-1);
            ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
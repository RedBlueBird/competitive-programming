#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Custom comparator that sort a vector pair by their 2nd integer value in increasing order
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

    //Similar to MovieFestival I
    //Greedily iterate the movies by the ones that ends the earliest
    //If no one watched a movie finishes before the next movie start,
    //let a new person watch join in until we run out of people.
    //Otherwise always take the person who finishes the latest to watch the next movie
    int ans = 0;
    int curr = k;
    multiset<int> watching;
    for (int i = 0; i < n; i++){
        auto next = watching.lower_bound(movies[i].first*-1);
        if (!watching.empty() && next != watching.end()){
            watching.erase(next);
            watching.insert(movies[i].second*-1);
            ans++;
        }
        else if (curr){
            curr--;
            watching.insert(movies[i].second*-1);
            ans++;
        }
    }

    //Output
    cout << ans;

    return 0;
}
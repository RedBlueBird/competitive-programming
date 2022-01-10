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
    //Find the value with the furthest right distance
    //Sort the segments
    int n;
    cin >> n;
    vector<tuple<int,int,int>> segments(n+1);
    int maxs = 0;
    for (int i = 1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        segments[i] = make_tuple(a,-b,i);
        maxs = max(maxs, b);
    }
    sort(segments.begin(), segments.end());

    //If the segment with the closest left distance also have the
    //furthest right distance, the answer will exist. False otherwise.
    if (-get<1>(segments[1]) == maxs){
        cout << get<2>(segments[1]);
    }else{
        cout << -1;
    }

    return 0;
}
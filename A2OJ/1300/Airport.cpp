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
    int n,m;
    cin >> n >> m;
    priority_queue<int> mins;
    priority_queue<int> maxs;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        maxs.push(a);
        mins.push(-a);
    }

    //Greedily find the minimal cost
    int maxAns = 0, minAns = 0;
    while (n--){
        int a;
        a = -1*mins.top();
        mins.pop();
        minAns += a;
        if (a != 1)
            mins.push(-1*(a-1));
        a = maxs.top();
        maxs.pop();
        maxAns += a;
        if (a != 1)
            maxs.push(a-1);
    }

    //Output
    cout << maxAns << " " << minAns;

    return 0;
}
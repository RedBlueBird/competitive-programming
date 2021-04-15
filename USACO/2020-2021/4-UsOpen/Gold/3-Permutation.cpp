#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<ll,ll,ll> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

struct Poll{
    ll x,y;
    bool operator ==(Poll b){
        return x==b.x&&y==b.y;
    }
};

ll dir(Poll p1, Poll p2, Poll p3){
    ll det = ((p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x));
    return det == 0 ? 0 : det > 0 ? 1 : -1;
}

bool within(Poll p1, Poll p2, Poll p3){
    if (dir(p1,p2,p3) == 0)
        return (p3.x>=min(p1.x,p2.x)&&p3.x<=max(p1.x,p2.x)&&(p3.y>=min(p1.y,p2.y))&&(p3.y<=max(p1.y,p2.y)));
    return false;
}

//bool test = false;
void permute(vector<Poll>& polls, vector<bool> visited, vector<ll> order, ll& ans){
//    if (test) return;
    if (order.size() == polls.size()-1){
//        test = true;

//        for (ll i: order)
//            cout << i << " ";
//        cout << "\n";
        vector<pair<Poll,Poll>> edges;
        edges.push_back(make_pair(polls[order[0]],polls[order[1]]));
        edges.push_back(make_pair(polls[order[1]],polls[order[2]]));
        edges.push_back(make_pair(polls[order[2]],polls[order[0]]));
//        for (auto i: edges)
//            cout << i.ff.x << " " << i.ff.y << " " << i.ss.x << " " << i.ss.y << "\n";
        vector<ll> debug = {1,2,4,5,3};
        for (ll i = 4; i < polls.size(); i++){
            ll count = 0;
            Poll p1 = polls[order[i-1]];
            stack<pair<Poll,Poll>> store;
            for (ll j = 1; j < polls.size(); j++){
                if (j == i) continue;
                Poll p2 = polls[order[j-1]];
                bool valid = true;
                for (ll k = 0; k < edges.size(); k++){
                    Poll p3 = edges[k].ff, p4 = edges[k].ss;
                    if (p1==p3||p1==p4||p2==p3||p2==p4) continue;
                    if ((dir(p1,p2,p3)!=dir(p1,p2,p4))&&(dir(p3,p4,p1)!=dir(p3,p4,p2)))
                        valid = false;
                    if (within(p1,p2,p3)||within(p1,p2,p4)||within(p3,p4,p1)||within(p3,p4,p2))
                        valid = false;
                    if (!valid) break;
                }
                if (valid) {
                    count++;
                    store.push(make_pair(p1,p2));
                }
                if (count > 3)
                    return;
            }
            if (count != 3)
                return;
            while (store.size()) {
                edges.push_back(store.top());
                store.pop();
            }
        }
        ans++;
//        cout << "true\n";
    }else{
        for (ll i = 1; i < polls.size(); i++){
            if (visited[i]) continue;
            visited[i] = true;
            order.push_back(i);
            permute(polls, visited, order, ans);
            order.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take Inputs
    ll n;
    cin >> n;
    vector<Poll> polls(n+1);
    for (ll i = 1; i <= n; i++)
        cin >> polls[i].x >> polls[i].y;

    vector<bool> visited(n+1);
    vector<ll> order;
    ll ans = 0;
    permute(polls, visited, order, ans);

    //Output
    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

void update(vector<ll>& segtree, int k, ll x){
    int len = segtree.size();
    k += len;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /=2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

ll sums(vector<ll>& segtree, int a, int b){
    int len = segtree.size();
    a += len; b += len;
    ll total = 0;
    while (a <= b){
        if (a%2)
            total += segtree[a++];
        if (!(b%2))
            total += segtree[b--];
        a/=2; b/=2;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    int len = 0;
    while ((1 << len) <= n+1) len++;
    len = (1 << len);
    vector<ll> segtree(2*len);
    vector<ll> costs(n+1);
    for (int i = 1; i <= n; i++){
        cin >> costs[i];
    }
    vector<int> childs(n+1);
    vector<int> head(n+1);
    for (int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        head[b] = a;
        childs[a]++;
    }

    ll ans = 0;
    priority_queue<pii> pages;
    for (int i = 1; i <= n; i++){
        if (childs[i] == 0){
            pages.push(make_pair(costs[i], i));
        }
    }

    int c = 0;
    while (pages.size()){
        int page = pages.top().ss;
        pages.pop();
        ans += sums(segtree, 0, page);
        ans += costs[page] * 3;
        update(segtree, page, costs[page]);
        childs[head[page]]--;
        if (childs[head[page]] == 0){
            pages.push(make_pair(costs[head[page]], head[page]));
        }
        c++;
        if (c == 2) break;
    }

    //Output
    cout << ans;

    return 0;
}
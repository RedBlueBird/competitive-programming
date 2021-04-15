#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Get the sum between range a and b in a segement tree
ll sum(vector<ll>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len;
    b += len;
    int total = 0;
    while (a <= b){
        if (a%2)
            total += segtree[a++];
        if (!(b%2))
            total += segtree[b--];
        a /= 2;
        b /= 2;
    }
    return total;
}

//Increase k-th element of segment tree by x
void update(vector<ll>& segtree, int k, ll x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n;
    cin >> n;
    vector<int> nums(n+1);
    vector<set<int>> index(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        index[nums[i]].insert(i);
    }

    //Convert the input into a query
    //Each number holds a range (left,right) where left is the closest index to number's left
    //where both have the same value, same applies to right
    //For each number, the amount of answer it contribute is same as finding the amount of numbers
    //that are between the current number's index and its' right index, where those numbers left are less or equal
    //to the current number's index
    //This problem can be converted to range query the amount of elements between two values that are less than k
    vector<pii> query;
    vector<ll> mins(n+2);
    for (int i = 1; i <= n; i++){
        auto it = index[nums[i]].lower_bound(i);
        int left, right;
        if (it == index[nums[i]].begin())
            left = 1;
        else
            left = *prev(it);
        if (next(it) == index[nums[i]].end())
            right = n+1;
        else
            right = *next(it);
        mins[i] = left;
        query.push_back(make_pair(i+1, i));
        query.push_back(make_pair(right, -i));
    }
    sort(query.begin(), query.end());

    int len = 0;
    while ((1 << len) <= n) len++;
    len = 1 << len;
    vector<ll> segtree(2*len);
    int c = n;
    vector<ll> sums(n+1);
    for (int i = query.size()-1; i >= 0; i--){
        while (c >= query[i].ff) {
            update(segtree, mins[c], 1);
            c--;
        }
        if (query[i].ss < 0)
            sums[query[i].ss*-1] -= sum(segtree, 0,query[i].ss*-1);
        else
            sums[query[i].ss] += sum(segtree, 0, query[i].ss);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += sums[i];

    //Output
    cout << ans;

    return 0;
}
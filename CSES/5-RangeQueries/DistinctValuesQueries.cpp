#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Check the sum between a-th and b-th element in a segment tree
int sum(vector<int>& segtree, int a, int b){
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

//Increase the k-th element by x in a segment tree
void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] += x;
    for (k/=2; k >= 1; k/=2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Treat query offline and sort
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<tiii> query(q);
    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        query[i] = make_tuple(b-1,a-1,i);
    }
    sort(query.begin(), query.end());

    //Compress the input and construct a segment tree
    vector<int> compress = nums;
    sort(compress.begin(), compress.end());
    map<int,int> convert;
    for (int i = 0; i < n; i++){
        if (!convert.count(compress[i]))
            convert[compress[i]] = i;
    }
    int len = 0;
    while ((1 << len) < n) len++;
    len = (1 << len);
    vector<int> segtree(2*len);

    //Scan from left to right
    //If the number is new, add that to the segment tree
    //Otherwise remove the previous existence of that number then add it again
    //This allows the number to be at the rightest index
    //Any query with left interval smaller than it will include it in the segment tree summation
    vector<int> ans(q);
    map<int,int> seen;
    int back = 0;
    for (int i = 0; i < n; i++){
        if (seen.count(convert[nums[i]])) update(segtree, seen[convert[nums[i]]], -1);
        seen[convert[nums[i]]] = i;
        update(segtree, i, 1);
        while (back != n && get<0>(query[back]) <= i){
            ans[get<2>(query[back])] = sum(segtree, get<1>(query[back]), get<0>(query[back]));
            back++;
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
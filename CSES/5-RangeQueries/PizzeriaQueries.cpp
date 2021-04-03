#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Set the k-th element in the segment tree to x
void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = x;
    for (k /= 2; k >= 1; k /= 2)
        segtree[k] = min(segtree[2*k], segtree[2*k+1]);
}

//Find the minimum value between range a and b in a segment tree
int mins(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    int result = INT_MAX;
    while (a <= b){
        if (a%2)
            result = min(result, segtree[a++]);
        if (!(b%2))
            result = min(result, segtree[b--]);
        a/=2;b/=2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    //Observe when there is a type 2 query, all the costs after/behind k are increasing by a constant of 1
    //If k shifts by c indices, the increase between k+1 and k+2 will still be 1
    //Due to this linear property we can percompute the minimum when k = 0 or k = n-1 (0-indexed) using 2 segment trees
    //If k is between 0 and n-1, we just take [0,k] from the first segtree [k,n-1] from the second segtree
    //And increase the result by k-1 and n-k respectively
    int len = 0;
    while ((1<<len) <= n) len++;
    len = (1<<len);
    vector<int> left(2*len);
    vector<int> right(2*len);
    for (int i = 1; i <= n; i++){
        left[i+len] = nums[i] + i - 1;
        right[i+len] = nums[i] + n - i;
    }
    for (int i = len/2; i >= 1; i /=2){
        for (int j = i; j < 2*i; j++){
            left[j] = min(left[2*j], left[2*j+1]);
            right[j] = min(right[2*j], right[2*j+1]);
        }
    }

    //Output
    for (int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            int k, x;
            cin >> k >> x;
            update(left, k, x+k-1);
            update(right,k,x+n-k);
        }else{
            int k, ans = INT_MAX;
            cin >> k;
            ans = min(ans, mins(left, k, n)-k+1);
            ans = min(ans, mins(right,1, k)-n+k);
            cout << ans << "\n";
        }
    }

    return 0;
}
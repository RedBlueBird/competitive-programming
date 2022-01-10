#include <bits/stdc++.h>
using namespace std;

void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = x;
    for (k /= 2; k >= 1; k /= 2)
        segtree[k] = segtree[2*k] + segtree[2*k+1];
}

int sums(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
    int sum = 0;
    while (a <= b){
        if (a%2){
            sum += segtree[a++];
        }
        if (!(b%2)){
            sum += segtree[b--];
        }
        a/=2; b/=2;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans(n + 1);
    vector<int> bounds(n + 1);
    vector<bool> trend(n, true);
    for (int i = 0; i < n; i++) {
        bounds[nums[i]] = i;
    }

    int len = 0;
    while ((1 << len) <= n) len++;
    len = (1 << len);
    vector<int> segtree(2 * len);

    for (int i = 1; i < n; i++) {
        int bound = max(bounds[i], bounds[i + 1]);
        trend[bounds[i]] = false;
        if (bounds[i] - 1 >= 0 && trend[bounds[i] - 1]) {
            update(segtree, bounds[i], 1);
        }
        if (bounds[i] + 1 < n && !trend[bounds[i] + 1]) {
            update(segtree, bounds[i] + 1, 0);
        }
        ans[i] = sums(segtree, 0, bound);
//            for (int j = len; j < 2 * len; j++) {
//                cout << segtree[j] << " ";
//            }
//            cout << "\n";
//            for (int j = 0; j < n; j++) {
//                cout << trend[j] << " ";
//            }
//            cout << "\n --- \n";
    }

    for (int i = 0; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Flip the state of x-th element in 1d segment tree
void update(vector<int>& segtree, int x){
    for (x /= 2; x >= 1; x /= 2){
        segtree[x] = segtree[2*x] + segtree[2*x+1];
    }
}

//Flip the state of (x,y)th element in 2d segment tree
void update2d(vector<vector<int>>& segtree, int x, int y){
    int len = segtree.size()/2;
    x += len; y += len;
    segtree[x][y] ^= 1;
    for (; x >= 1; x /= 2){
        if (x < len)
            segtree[x][y] = segtree[2*x][y] + segtree[2*x+1][y];
        update(segtree[x], y);
    }
}

//Get the sum between x1 and x2 in 1d segment tree
int sum(vector<int>& segtree, int x1, int x2){
    int total = 0;
    while (x1 <= x2){
        if (x1%2)
            total += segtree[x1++];
        if (!(x2%2))
            total += segtree[x2--];
        x1 /= 2;
        x2 /= 2;
    }
    return total;
}

//Get the sum between (x1,y1) and (x2,y2) rectangle in 2d segment tree
int sum2d(vector<vector<int>>& segtree, int x1, int y1, int x2, int y2){
    int len = segtree.size()/2;
    x1 += len; x2 += len; y1 += len; y2 += len;
    int total = 0;
    while (x1 <= x2){
        if (x1%2)
            total += sum(segtree[x1++], y1, y2);
        if (!(x2%2))
            total += sum(segtree[x2--], y1, y2);
        x1 /= 2;
        x2 /= 2;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take Inputs
    //Construct prefix sum 2d segment tree
    int n, q;
    cin >> n >> q;
    int len = 0;
    while ((1 << len) <= n) len++;
    len = 1 << len;
    vector<vector<int>> segtree(2*len, vector<int>(2*len));
    for (int i = 1; i <= n; i++){
        string a;
        cin >> a;
        for (int j = 1; j <= n; j++){
            if (a[j-1] == '*') {
                segtree[i + len][j + len]++;
            }
        }
    }
    for (int i = len/2; i >= 1; i /= 2){
        for (int j = i; j < 2*i; j++){
            for (int k = len; k < 2*len; k++){
                segtree[j][k] = segtree[2*j][k] + segtree[2*j+1][k];
            }
        }
    }
    for (int k = 1; k < 2*len; k++){
        for (int i = len/2; i >= 1; i /= 2){
            for (int j = i; j < 2*i; j++){
                segtree[k][j] = segtree[k][2*j] + segtree[k][2*j+1];
            }
        }
    }

    //The problem is basically describing the bare bones for the functions of a 2d segment tree
    //Output
    for (int i = 0; i < q; i++){
        int type;
        cin >> type;
        if (type == 1){
            int a,b;
            cin >> a >> b;
            update2d(segtree, a, b);
        }else{
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            cout << sum2d(segtree, a,b,c,d) << "\n";
        }
    }

    return 0;
}
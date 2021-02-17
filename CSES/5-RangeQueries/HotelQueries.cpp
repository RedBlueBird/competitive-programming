#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Find the maximum value from elements a to b in a segment tree
int maximum(vector<int>& segtree, int a, int b){
    int c = segtree.size()/2;
    a += c;
    b += c;
    int res = -1;
    while (a <= b){
        if (a%2)
            res = max(res, segtree[a++]);
        if (!(b%2))
            res = max(res, segtree[b--]);
        a /=2;
        b /=2;
    }
    return res;
}

//Increase k-th element in the segment tree by x
void add(vector<int>& segtree, int k, int x){
    int c = segtree.size()/2;
    k += c;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = max(segtree[2*k],segtree[2*k+1]);
    }
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct Maximum segment tree
    int n, m;
    cin >> n >> m;
    int c = 0;
    while ((1 << c) < n)
        c++;
    c = 1 << c;
    vector<int> segtree(2*c);
    for (int i = 0; i < n; i++)
        cin >> segtree[i+c];
    for (int i = c/2; i >= 1; i /= 2)
        for (int j = i; j < 2*i; j++)
            segtree[j] = max(segtree[2*j], segtree[2*j+1]);

    //Array maximum(segtree,0,j) where 0<=j<n never decreases
    //For each query k, the first index in the tree that is at least k can be found with binary search
    //If no index found, output 0 for that query
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        int a = 0, b = n-1;
        while ((b-a)>1){
            if (maximum(segtree,0,(a+b)/2)>=k){
                b -= (b-a)/2;
            }else{
                a += (b-a)/2;
            }
        }
        if (maximum(segtree, 0, b) <k){
            cout << 0 << " ";
            continue;
        }
        if (maximum(segtree, 0, a) < k) a = b;
        add(segtree, a, -k);
        cout << a+1 << " ";
    }

    return 0;
}
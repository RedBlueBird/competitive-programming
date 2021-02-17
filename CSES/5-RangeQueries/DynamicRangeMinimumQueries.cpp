#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Set the k-th leaf of the segment tree to x
void add(vector<int>& segtree, int k, int x){
    int c = segtree.size()/2;
    k += c;
    segtree[k] = x;
    for (k /= 2; k >= 1; k/=2){
        segtree[k] = min(segtree[2*k], segtree[2*k+1]);
    }
}

//Find the minimum value between range [a,b] in a segment tree
int minimum(vector<int>& segtree, int a, int b){
    int c = segtree.size()/2;
    a += c;
    b += c;
    int mins = INT_MAX;
    while (a <= b){
        if (a%2)
            mins = min(mins, segtree[a++]);
        if (!(b%2))
            mins = min(mins, segtree[b--]);
        a /= 2;
        b /= 2;
    }
    return mins;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct the minimum segment tree
    int n, q;
    cin >> n >> q;
    int c = 0;
    while ((1<<c) < n+1)
        c++;
    c = 1 << c;
    vector<int> segtree(2*c);
    for (int i = 1; i <= n; i++){
        cin >> segtree[i+c];
    }
    for (int i = c/2; i >= 1; i /=2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = min(segtree[2*j],segtree[2*j+1]);
        }
    }

    //For each query, add when needed, output minimum value when asked
    for (int i = 0; i < q; i++){
        int type, a,b;
        cin >> type >> a >> b;
        if (type==1){
            add(segtree, a, b);
        }else{
            cout << minimum(segtree, a,b) << "\n";
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Sum between two indices of the segment tree
int sum(vector<ll>& segtree, int a, int b){
    int c = segtree.size()/2;
    a += c; b += c;
    int s = 0;
    while (a <= b){
        if (a%2)
            s += segtree[a++];
        if (!(b%2))
            s += segtree[b--];
        a /= 2;
        b /= 2;
    }
    return s;
}

//Increase the element at k by x
void add(vector<ll>& segtree, int k, ll x){
    int c = segtree.size()/2;
    k += c;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = segtree[2*k]+segtree[2*k+1];
    }
}

int main() {
    ofstream fout("haircut.out");
    ifstream fin("haircut.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct segment tree
    //The answer for each hair length
    //Is the amount of hairs in front of the current hair that are longer than it
    int n;
    fin >> n;
    int c = 0;
    while ((1 << c) <= n+1) {
        c++;
    }
    c = 1 << c;
    vector<ll> segtree(2*c);
    vector<ll> ans(n+2);
    for (int i = 1; i <= n; i++){
        int a;
        fin >> a;
        ans[a+1] += sum(segtree, a+1, n+1);
        add(segtree, a, 1);
    }

    //Output the answers
    ll total = 0;
    for (int i = 0; i < n; i++){
        total += ans[i];
        fout << total << "\n";
    }

    return 0;
}


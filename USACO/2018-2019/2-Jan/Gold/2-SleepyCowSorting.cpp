#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Find the sum between value a and b in a segment tree
int sum(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len;
    b += len;
    int sums = 0;
    while (a <= b){
        if (a%2)
            sums += segtree[a++];
        if (!(b%2))
            sums += segtree[b--];
        a /= 2;
        b /= 2;
    }
    return sums;
}

//Increase the k-th element of the segment tree by x
void add(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] += x;
    for (k /= 2; k >= 1; k/= 2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

int main() {
    ofstream fout("sleepy.out");
    ifstream fin("sleepy.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Initialize the segment tree
    int n;
    fin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }
    int len = 0;
    while ((1 << len) <= n) len++;
    len = 1 << len;
    vector<int> segtree(2*len);

    //Greedily construct the segment tree based on the increasing sequence at the back
    int size = 1;
    add(segtree, cows[n-1], 1);
    while (size != n && cows[n-size-1] < cows[n-size]){
        add(segtree, cows[n-size-1], 1);
        size++;
    }

    //For every output
    //The answer can be computed as below
    fout << n-size << "\n";
    for (int i = 0; i < n-size; i++){
        fout << n-size-i-1 + sum(segtree, 0, cows[i]);
        add(segtree, cows[i], 1);
        if (i != n-size-1)
            fout << " ";
    }

    return 0;
}


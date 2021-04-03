#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second
const ll mod = 1e9+7;

//Increase k-th element of segment tree by x
void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

//Find the sum between ranges a and b in segment tree
int sum(vector<int>& segtree, int a, int b){
    int len = segtree.size()/2;
    a += len; b += len;
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

int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
//    ifstream fin("../input.txt");
//    ofstream fout("../output.txt");

    //Take inputs
    //Sort the ranges
    int n;
    fin >> n;
    vector<pii> ranges(n+1);
    for (int i = 0; i <= n; i++){
        ranges[i] = make_pair(INT_MAX, 0);
    }
    for (int i = 1; i <= 2*n; i++){
        int a;
        fin >> a;
        ranges[a].ff = min(ranges[a].ff,i);
        ranges[a].ss = max(ranges[a].ss,i);
    }
    sort(ranges.begin(), ranges.end());

    //Construct segment tree
    //Because the ranges are sorted from left to right
    //The amount of intersections a range covers is same as the
    //amount of end points of other ranges the range contains
    int len = 0;
    while ((1<<len) <= 2*n) len++;
    len = (1<<len);
    vector<int> segtree(2*len);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += sum(segtree, ranges[i].ff, ranges[i].ss);
        update(segtree, ranges[i].ss, 1);
    }

    //Output
    fout << ans;

    return 0;
}


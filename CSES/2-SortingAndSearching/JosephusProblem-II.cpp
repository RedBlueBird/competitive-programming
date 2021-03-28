#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//Set the k-th element in the segment tree to x
void update(vector<int>& segtree, int k, int x){
    int len = segtree.size()/2;
    k += len;
    segtree[k] = x;
    for (k/=2; k >= 1; k/=2){
        segtree[k] = segtree[2*k]+segtree[2*k+1];
    }
}

//Get the sum between elements in range a and b in segment tree
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
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, k;
    cin >> n >> k;
    k++;

    //Construct segment tree
    int len = 0;
    while ((1 << len) <= n) len++;
    len = (1 << len);
    vector<int> segtree(2*len);
    for (int i = len+1; i <= len+n; i++)
        segtree[i] = 1;
    for (int i = len/2; i >= 1; i/=2){
        for (int j = i; j < 2*i; j++){
            segtree[j] = segtree[2*j] + segtree[2*j+1];
        }
    }

    //Use a segment tree to keep track of all the children
    //Due to the property of prefix sum is always non-decreasing
    //Use binary search to find the index where the curr-th children gets eliminated
    int curr = k%n;
    if (curr == 0) curr = n;
    for (int i = n-1; i >= 0; i--){
        int a = 1, b = n;
        while ((b-a)>1){
            if (sum(segtree, 0, (a+b)/2) < curr){
                a += (b-a)/2;
            }else{
                b -= (b-a)/2;
            }
        }
        if (!(sum(segtree, 0, a) == curr)) a = b;
        cout << a << " ";
        update(segtree, a, 0);
        if (i == 0) break;
        curr = (sum(segtree,0,a) + k)%i;
        if (curr == 0) curr = i;
    }

    return 0;
}
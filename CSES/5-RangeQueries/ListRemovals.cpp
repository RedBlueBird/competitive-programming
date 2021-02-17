#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Increase the k-th element of the binary indexed tree by x
void add(vector<int>& bitree, int k, int x){
    while (k < int(bitree.size())){
        bitree[k] += x;
        k += k&-k;
    }
}

//Find the sum of elements up to k in the binary indexed tree
int sum(vector<int>& bitree, int k){
    int s = 0;
    while (k){
        s += bitree[k];
        k -= k&-k;
    }
    return s;
}

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    //Construct binary indexed tree
    int n;
    cin >> n;
    vector<int> nums(n+1);
    vector<int> bitree(n+1);
    for (int i = 1; i <= n; i++){
        cin >> nums[i];
        add(bitree, i, 1);
    }

    //The content of the input array doesn't matter
    //Each element weight 1 when not removed, 0 otherwise
    //sum(bitree,j) for 0<=j<n, never decreases
    //For each query k, binary search the sum array to find the desired index
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        int a = 1, b = n;
        while ((b-a)>1){
            if (sum(bitree, (a+b)/2) >= k){
                b -= (b-a)/2;
            }else{
                a += (b-a)/2;
            }
        }
        if (sum(bitree,a) < k) a = b;
        add(bitree, a, -1);
        cout << nums[a] << " ";
    }

    return 0;
}
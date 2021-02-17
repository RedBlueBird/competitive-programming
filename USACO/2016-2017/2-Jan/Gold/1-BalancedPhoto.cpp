#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define ff first
#define ss second

//Find the sums of values from 0 to k-th index of BIT
int sum(vector<int>& bitree, int k){
    int s = 0;
    while (k){
        s += bitree[k];
        k -= k&-k;
    }
    return s;
}

//Increase the k-th number in the BIT by x
void add(vector<int>& bitree, int k, int x){
    while (k <= int(bitree.size())){
        bitree[k] += x;
        k += k&-k;
    }
}

int main() {
    ofstream fout("bphoto.out");
    ifstream fin("bphoto.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Compress the heights from 0 - 1e9 to 0 - 1e5
    int n;
    fin >> n;
    map<int,int> compress;
    vector<int> heights(n);
    for (int i = 0; i < n; i++){
        fin >> heights[i];
    }
    vector<int> nums = heights;
    sort(nums.begin(), nums.end());
    int c = 1;
    for (int i = 0; i < n; i++){
        if (!compress.count(nums[i]))
            compress[nums[i]] = c++;
        nums[i] = compress[nums[i]];
    }

    //Using binary-indexed-tree to check the total elements greater than the current element
    //Scan from left to right, and right to left
    //When double of left[i] is less than right[i], i-th cow is unbalanced. Vice versa.
    vector<int> left(n);
    vector<int> right(n);
    vector<int> lbitree(c);
    vector<int> rbitree(c);
    for (int i = 0; i < n; i++){
        left[i] = i-sum(lbitree, compress[heights[i]]);
        add(lbitree, compress[heights[i]], 1);
    }
    for (int i = n-1; i >= 0; i--){
        right[i] = (n-i-1)-sum(rbitree, compress[heights[i]]);
        add(rbitree, compress[heights[i]], 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (left[i]*2 < right[i] || right[i]*2 < left[i])
            ans++;
    }

    //Output
    fout << ans;

    return 0;
}


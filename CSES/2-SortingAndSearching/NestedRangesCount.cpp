#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//If the first value is the same, sort the second value in decreasing order
//Otherwise sort the first value in increasing order
bool reverseSort(tiii a, tiii b){
    if (get<0>(a) == get<0>(b))
        return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}

//Increase the k-th element by x in the binary indexed tree
void add(vector<int>& bitree, int k, int x){
    while (k < int(bitree.size())){
        bitree[k] += x;
        k += k&-k;
    }
}

//Find the sum of elements in the binary indexed tree up to k
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
    //Compress all the values to 1 - 1e5 scale
    //Sort the ranges
    int n, a,b;
    cin >> n;
    vector<tiii> ranges(n);
    vector<int> nums;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        ranges[i] = make_tuple(a,b,i);
        nums.push_back(a);
        nums.push_back(b);
    }
    sort(nums.begin(), nums.end());
    int k = 1;
    unordered_map<int,int> compress;
    for (int i: nums){
        if (!compress.count(i)){
            compress[i] = k++;
        }
    }
    sort(ranges.begin(), ranges.end(), reverseSort);

    //Create a hash table to store all the occurrence of the duplicate ranges
    //Scan left to right while constructing a left binary indexed tree to count all the ranges larger than the current
    //Scan right to left while constructing a right binary indexed tree to count all the ranges smaller than the current
    vector<int> larger(n);
    vector<int> smaller(n);
    unordered_map<ll,int> ldup;
    unordered_map<ll,int> rdup;
    for (tiii i: ranges){
        int a,b,c;
        tie(a,b,c) = i;
        ldup[compress[a]*k+compress[b]]++;
    }
    rdup = ldup;
    vector<int> lbitree(k);
    for (int i = 0; i < n; i++){
        int a,b,c;
        tie(a,b,c) = ranges[i];
        larger[c] = i-sum(lbitree,compress[b]-1);
        larger[c] += --ldup[compress[a]*k+compress[b]];
        add(lbitree, compress[b],1);
    }
    vector<int> rbitree(k);
    for (int i = n-1; i >= 0; i--){
        int a,b,c;
        tie(a,b,c) = ranges[i];
        smaller[c] = sum(rbitree, compress[b]);
        smaller[c] += --rdup[compress[a]*k+compress[b]];
        add(rbitree, compress[b], 1);
    }

    //Output
    for (int i: smaller){
        cout << i << " ";
    }
    cout << "\n";
    for (int i: larger){
        cout << i << " ";
    }

    return 0;
}
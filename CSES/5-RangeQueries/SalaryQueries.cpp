#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int sum(vector<int>& bitree, int k){
    int total = 0;
    while (k > 0){
        total += bitree[k];
        k -= k&-k;
    }
    return total;
}

void update(vector<int>& bitree, int k, int x){
    while (k < bitree.size()){
        bitree[k] += x;
        k += k&-k;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n, q;
    cin >> n >> q;
    vector<int> nums(n+1);
    vector<int> compress(1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        compress.push_back(nums[i]);
    }
    vector<tiii> query;
    for (int i = 0; i < q; i++){
        char type;
        int a,b;
        cin >> type >> a >> b;
        compress.push_back(b);
        if (type == '?')
            compress.push_back(a);
        query.push_back(make_tuple((type == '!'? 1:0), a, b));
    }
    sort(compress.begin(), compress.end());
    unordered_map<int,int> convert;
    int c = 0;
    for (int i = 0; i < compress.size(); i++){
        if (!convert.count(compress[i]))
            convert[compress[i]] = c++;
    }

    vector<int> bitree(c);
    for (int i = 1; i <= n; i++){
        update(bitree, convert[nums[i]], 1);
    }
//    for (auto i: convert){
//        cout << i.first << " : " << i.second << "\n";
//    }
//    for (int i = 1; i <= 5; i++){
//        cout << sum(bitree, i) << " ";
//    }
//    cout << "\n";

    for (int i = 0; i < q; i++){
        if (get<0>(query[i]) == 1) {
            update(bitree, convert[nums[get<1>(query[i])]], -1);
            nums[get<1>(query[i])] = get<2>(query[i]);
            update(bitree, convert[nums[get<1>(query[i])]], 1);
        }else{
            cout << sum(bitree, convert[get<2>(query[i])]) - sum(bitree, convert[get<1>(query[i])]-1) << "\n";
        }
    }

    return 0;
}
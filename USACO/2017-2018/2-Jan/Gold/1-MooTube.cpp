#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

//Find the root of the subtree the node resides in
int find(vector<int>& top, int k){
    return k == top[k]? k : top[k] = find(top, top[k]);
}

//Merge two subtrees the two nodes resides in if possible
bool merge(vector<int>& top, vector<int>& size, int a, int b){
    a = find(top,a);
    b = find(top,b);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a,b);
    top[b] = a;
    size[a] += size[b];
    return true;
}

int main() {
    ofstream fout("mootube.out");
    ifstream fin("mootube.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs and sort them
    int n, q;
    fin >> n >> q;
    vector<tiii> edges;
    for (int i = 1; i < n; i++){
        int a,b,c;
        fin >> a >> b >> c;
        edges.push_back(make_tuple(c,a,b));
    }
    vector<tiii> query;
    for (int i = 0; i < q; i++){
        int a,b;
        fin >> a >> b;
        query.push_back(make_tuple(a,b,i));
    }
    sort(edges.begin(), edges.end());
    sort(query.begin(), query.end());

    //Perform offline query with disjoint-set-union data structure
    //Merge nodes with edges that have the highest relevance to the lowest
    //Answer queries with the highest requirement to the lowest
    //The answer to each query is the size of the subtree the node resides in
    vector<int> top(n+1);
    vector<int> size(n+1,1);
    for (int i = 0; i <= n; i++)
        top[i] = i;
    vector<int> ans(q);
    int c = n-2;
    for (int i = q-1; i >= 0; i--){
        while (c >= 0 && get<0>(edges[c]) >= get<0>(query[i])){
            merge(top, size, get<1>(edges[c]), get<2>(edges[c]));
            c--;
        }
        ans[get<2>(query[i])] = size[find(top,get<1>(query[i]))]-1;
    }

    //Output
    for (int i = 0; i < q; i++){
        fout << ans[i] << "\n";
    }

    return 0;
}


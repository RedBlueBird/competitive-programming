#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second

//Finding the root node of the current node's subtree
int find(int target, vector<int>& top){
    return target == top[target] ? target : target = find(top[target],top);
}

//Merge two subtrees together if both subtrees have different roots
bool merge(int a, int b, vector<int>& top, vector<int>& size){
    a = find(a, top);
    b = find(b, top);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a,b);
    top[b] = a;
    size[a] += size[b];
    return true;
}

int main() {
    ofstream fout("moocast.out");
    ifstream fin("moocast.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i].first >> cows[i].second;
    }

    //Calculate all the distances between cows
    //Perform Union-Find for minimum spanning tree
    //The last valid distance used in the tree is the answer
    vector<tuple<int,int,int>> dists;
    vector<int> size(n,1);
    vector<int> top(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        top[i] = i;
        for (int j = 0; j < n; j++){
            dists.push_back(make_tuple(pow(cows[i].first-cows[j].first, 2) + pow(cows[i].second-cows[j].second, 2), i, j));
        }
    }
    sort(dists.begin(),dists.end());
    for (tuple<int,int,int> i: dists){
        int a,b,c;
        tie(a,b,c) = i;
        if (merge(b,c, top, size)){
            ans = max(ans, a);
        }
    }

    //Output
    fout << ans;

    return 0;
}
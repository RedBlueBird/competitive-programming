#include <bits/stdc++.h>
#define ff first
#define ss second
typedef long long ll;
using namespace std;

const int MAXS = 1e5+1;
int tiles[MAXS];
pair<int,int> boots[MAXS];
int tileOrder[MAXS], bootOrder[MAXS], rights[MAXS], lefts[MAXS];

//Comparator sorting the index of the snow tiles based on their depth in decreasing order
bool tilescmp(const int& a, const int& b){
    return tiles[a] > tiles[b];
}

//Comparator sorting the index of the boots based on their size in decreasing order
bool bootscmp(const int& a, const int& b){
    return boots[a].ff > boots[b].ff;
}

int main() {
    ofstream fout("snowboots.out");
    ifstream fin("snowboots.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Construct the double linked list
    //Construct the indices lists and sort them
    //Warning: don't using lambda comparators, they will reach TLE
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++){
        fin >> tiles[i];
        tileOrder[i] = i;
        rights[i] = i+1;
        lefts[i] = i-1;
    }
    for (int i = 0; i < m; i++){
        fin >> boots[i].ff >> boots[i].ss;
        bootOrder[i] = i;
    }
    sort(tileOrder, tileOrder+n, tilescmp);
    sort(bootOrder, bootOrder+m, bootscmp);

    //Check from the boots with largest size to the one with smallest
    //For each boot, as long as there are snow tiles that are greater than the boot's size
    //Remove them and remove them from the double linked list
    //The boot can be equipped if its distance is >= the maximum distance between two nodes in the linked list
    int c = 0;
    int maxs = 0;
    vector<bool> ans(m);
    for (int i = 0; i < m; i++){
        int depth, dist;
        tie(depth, dist) = boots[bootOrder[i]];
        while (c < n && tiles[tileOrder[c]] > depth){
            rights[lefts[tileOrder[c]]] = rights[tileOrder[c]];
            lefts[rights[tileOrder[c]]] = lefts[tileOrder[c]];
            maxs = max(maxs, rights[tileOrder[c]]-lefts[tileOrder[c]]);
            c++;
        }
        ans[bootOrder[i]] = dist >= maxs;
    }

    //Output
    for (bool i: ans){
        fout << i << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define ff first
#define ss second

int main() {
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    int n;
    fin >> n;
    vector<int> computed(n);
    vector<int> truth(n);
    for (int i = 0; i < n; i++){
        fin >> computed[i];
    }
    for (int i = 0; i < n; i++){
        fin >> truth[i];
    }

    vector<int> diffs;
    for (int i = 0; i < n; i++){
        fout << computed[i] << " " << truth[i] << "\n";
        if (computed[i] != truth[i])
            diffs.push_back(i+1);
    }
    for (int i: diffs)
        fout << i << " ";
    fout << "\n" << diffs.size();

    return 0;
}


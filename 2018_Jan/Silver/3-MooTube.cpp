#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
//    ofstream fout("rental.out");
//    ifstream fin("rental.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    int n, m;
    fin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        fin >> a >> b >> c;
        graph[a-1].push_back(c);
        graph[b-1].push_back(c);
    }
    for (int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        int ans = 0;
        for (int j: graph[b-1]){
            if (j >= a){
                ans++;
            }
        }
        fout << ans << "\n";
    }

    return 0;
}
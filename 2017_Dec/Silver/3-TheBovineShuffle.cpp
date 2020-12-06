#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout ("shuffle.out");
    ifstream fin  ("shuffle.in");
//    ofstream fout ("../output.txt");
//    ifstream fin ("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> shuffle(n);
    for (int i = 0; i < n; i++){
        fin >> shuffle[i];
    }

    //Detect cycles, and count all the cycles and their lengths
    vector<int> visited(n, -1);
    vector<int> nodeValue(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        int c = 0;
        int curr = i;
        while (visited[curr] == -1){
            visited[curr] = i;
            nodeValue[curr] = c++;
            curr = shuffle[curr]-1;
        }
        cout << curr << " ";
        if (visited[curr] == i){
            ans += c - nodeValue[curr];
        }
    }

    //Output
    fout << ans;

    return 0;
}
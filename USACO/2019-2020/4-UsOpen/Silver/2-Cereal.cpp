#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("cereal.out");
    ifstream fin("cereal.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    int n, m;
    fin >> n >> m;
    vector<int> boxes(m+1, INT_MAX);
    vector<pair<int,int>> cows(n);
    for (int i = 0; i < n; i++){
        fin >> cows[i].first >> cows[i].second;
    }

    //Iterate backward
    //Make the cereal boxes pointers to the last cow that chose them
    //Once a prior cow choose a chosen box, the previous cow will choose their 2nd box,
    //if 2nd box already chosen, the previous cow will choose their 2nd box, and repeat.
    //If the said box is already the previous cow's 2nd box, then remove them from total
    //This is have a max runtime of O(2*n) => O(n) despite the while loop inside
    vector<int> ans(n);
    int total = 0;
    for (int i = n-1; i >= 0; i--){
        total++;
        int curr = cows[i].first;
        int picked = boxes[curr];
        int cow = i;
        while (true) {
            boxes[curr] = cow;
            if (picked != INT_MAX) {
                if (cows[picked].first == curr && picked < boxes[cows[picked].second]) {
                    cow = picked;
                    curr = cows[picked].second;
                    picked = boxes[curr];
                } else {
                    total--;
                    break;
                }
            }else{
                break;
            }
        }
        ans[i] = total;
    }

    //Output
    for (int i: ans)
        fout << i << "\n";

    return 0;
}
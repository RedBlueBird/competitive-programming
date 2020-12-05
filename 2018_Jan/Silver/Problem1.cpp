#include <bits/stdc++.h>

using namespace std;

int main() {
//    ofstream fout ("homework.out");
//    ifstream fin  ("homework.int");
    ofstream fout ("..\\..\\output.txt");
    ifstream fin ("..\\..\\input.txt");
    
    int n;
    fin >> n;
    vector<int> hwk(n);
    for (int i = 0; i < n; i++){
        fin >> hwk[i];
    }
    cout << n;

//    float bestScore;
//    vector<int> ans;
//    int minScore;
//    int sum = hwk[1];
//    for (int i = n-2; i >= 0; i--){
//        sum += hwk[i];
//        minScore = min(minScore, hwk[i]);
//        float newScore = (float)((sum-minScore)/(n-i-1));
//        if (bestScore < newScore){
//            bestScore = newScore;
//            ans = vector<int>{i};
//        }
//        else if (bestScore == newScore){
//            ans.push_back(i);
//        }
//    }
//    for (int i: ans){
//        cout << i << "\n";
//    }

    return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ofstream fout("cardgame.out");
    ifstream fin("cardgame.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs
    //Keep track of the first halves and second halves of opponent and sort them
    int n;
    fin >> n;
    vector<int> oppo(n);
    vector<int> left(n/2);
    vector<int> right(n/2);
    for (int i = 0; i < n; i++){
        fin >> oppo[i];
        if (i < n/2){
            left[i] = oppo[i];
        }else{
            right[i-n/2] = oppo[i];
        }
    }
    sort(oppo.begin(), oppo.end());
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    //Find the remaining cards that doesn't exist in opponent's hand
    //Greedily take the highest value card against the first halves
    //Greedily take the lowest value card against the second halves
    int ans = 0;
    vector<int> cards;
    int c = n-1;
    for (int i = 2*n; i > 0; i--){
        while (c >= 0 && oppo[c] > i){
            c--;
        }
        if (oppo[c] < i){
            cards.push_back(i);
        }else if (c <= 0 && i < oppo[c]){
            cards.push_back(i);
        }
    }
    c = 0;
    for (int i = n/2-1; i >= 0; i--){
        if (left[i] < cards[c]){
            c++;
            ans++;
        }
    }
    c = n-1;
    for (int i = 0; i < n/2; i++){
        if (right[i] > cards[c]){
            c--;
            ans++;
        }
    }

    //Output
    fout << ans;

    return 0;
}
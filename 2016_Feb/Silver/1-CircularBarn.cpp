#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
//    ofstream fout("cbarn.out");
//    ifstream fin("cbarn.in");
    ofstream fout("../output.txt");
    ifstream fin("../input.txt");

    //Take inputs
    int n;
    fin >> n;
    vector<int> barns(n);
    for (int i = 0; i < n; i++){
        fin >> barns[i];
    }

    //Fill all the zeros from bottom up.
    //This greedy method is guarantee to work because cows are only
    //allowed to move clockwise.
    int a = n-2;
    int ans = 0;
    for (; a >= 0; a--){
        if (barns[a] == 0 && barns[a+1] != 0){
            break;
        }
    }
    int counter = 0;
    int b = (a-1+n)%n;
    int k = 0;
    while(counter < n) {
        if (barns[a] == 0) {
            while (barns[b] == 0) {
                b = (b - 1 + n) % n;
            }
            barns[b]--;
            barns[a]++;
            if (b < a){
                ans += (int)pow(abs(a-b),2);
            }else{
                ans += (int)pow(abs(n-b+a), 2);
            }
            if (!barns[b]) counter--;
            counter++;
        }
        else{
            counter++;
        }
        a = (a-1+n)%n;
        b = (a-1+n)%n;
        for (int i: barns){
            cout << i << " ";
        }
        cout << " | " << ans << "\n";
    }

    //Output
    fout << ans;

    return 0;
}
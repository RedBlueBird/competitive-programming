#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//Find the greatest common factor of two numbers
int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    ofstream fout("pails.out");
    ifstream fin("pails.in");
//    ofstream fout("../output.txt");
//    ifstream fin("../input.txt");

    //Take inputs, such that x always greater than y
    int x,y,k,m;
    fin >>x>>y>>k>>m;
    if (y>x){
        swap(x,y);
    }

    //Find all possible values that can be created from the two cups
    //The one closest to the target value have the minimum difference thus the answer
    int ans = INT_MAX;
    int inter = gcd(x,y);
    int curr = y;
    int time = 1;
    for (int i = 0; i < (x + y)/inter-1; i++){
        if (time <= k){
            ans = min(ans, abs(curr-m));
            if (curr + y > x + y){
                curr -= x;
            }
            else{
                curr += y;
            }
            time += 2;
            cout << curr << " " << time << " \n";
        }
        else break;
    }
    time = 1;
    curr = x;
    for (int i = 0; i < (x + y)/inter-1; i++){
        if (time <= k){
            ans = min(ans, abs(curr-m));
            if (curr < y){
                curr += x;
            }
            else{
                curr -= y;
            }
            time += 2;
            cout << curr << " " << time << " \n";
        }
        else break;
    }
    if (k >= 2 && abs(m-x-y) < ans){
        ans = min(ans,abs(m-x-y));
    }

    //Output
    fout << ans;

    return 0;
}
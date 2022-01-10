#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ff first
#define ss second
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Process Inputs
    int n;
    cin >> n;
    string input;
    cin >> input;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++){
        a.push_back(int(input[i]-'0'));
    }
    for (int i = n; i < 2*n; i++){
        b.push_back(int(input[i]-'0'));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    //Sort the input numbers
    //Greedily compare both array of numbers
    //From smallest to largest, if kth smallest number is smaller than kth largest number
    //when it is shouldn't, then the answer will be NO, else YES, and vice versa.
    if (a[0] > b[0]){
        for (int i = 0; i < n; i++){
            if (a[i] <= b[i]){
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }
    else{
        for (int i = 0; i < n; i++){
            if (a[i] >= b[i]){
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }

    return 0;
}
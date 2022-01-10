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
    //Count the occurrence of 100s and 200s
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        if (k == 100){
            a++;
        }else{
            b++;
        }
    }

    //Output YES/NO based on the following 2 rules
    if ((a+2*b)%2 || (b%2 && a==0)){
        cout << "NO";
    }else{
        cout << "YES";
    }

    return 0;
}
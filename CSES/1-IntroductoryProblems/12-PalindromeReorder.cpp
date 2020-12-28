#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int counts[26];
string convert = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    string raw;
    cin >> raw;

    //Convert the char in the string to numbers
    int n = raw.size();
    int odds = 0;
    int track = -1;
    for (int i = 0; i < n; i++){
        int index = raw[i]-'A';
        if (counts[index]%2) odds--;
        else odds++;
        counts[index]++;
    }

    //Guarantee no solution when there are more than 1 odd letter type
    if (odds > 1){
        cout << "NO SOLUTION";
        return 0;
    }

    //Output a palindrome by going through the list back and forth
    for (int i = 0; i < 26; i++) {
        if (counts[i]%2) {
            track = i;
            continue;
        }
        for (int j = 0; j < counts[i]/2; j++)
            cout << convert[i];
    }
    if (track != -1)
        for (int i = 0; i < counts[track]; i++)
            cout << convert[track];
    for (int i = 25; i >= 0; i--) {
        if (counts[i]%2) continue;
        for (int j = 0; j < counts[i]/2; j++)
            cout << convert[i];
    }

    return 0;
}
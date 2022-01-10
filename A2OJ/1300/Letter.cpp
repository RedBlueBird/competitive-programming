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
    //Count the letters in the news string
    //If the same letter appears more in the text string than the news string,
    //then the answer will be false, true otherwise.
    string news;
    string text;
    getline(cin, news);
    getline(cin, text);
    int n = news.size();
    int m = text.size();
    vector<int> count(101);
    for (int i = 0; i < n; i++){
        if (news[i] == ' ') continue;
        count[news[i]-'A']++;
    }

    //Output
    for (int i = 0; i < m; i++){
        if (text[i] == ' ') continue;
        if (--count[text[i]-'A'] < 0){
            cout << "\n";
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
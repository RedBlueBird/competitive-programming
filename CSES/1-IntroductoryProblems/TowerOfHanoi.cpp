#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

stack<int> towers[3];

int main() {
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);

    //Take inputs
    int n;
    cin >> n;
    for (int i = n; i > 0; i--){
        towers[0].push(i);
    }

    //A simple solution for the toy puzzle is to
    //alternate moves between the smallest piece and a non-smallest piece.
    //When moving the smallest piece, always move it to the next position in the same direction
    //Right if # pieces is even, left otherwise
    //If there is no tower position in the chosen direction, move the piece to the opposite end,
    //but then continue to move in the correct direction.
    //Source https://en.wikipedia.org/wiki/Tower_of_Hanoi
    int dir = n%2 ? -1 : 1;
    bool turn = true;
    int index = 0;
    cout << (1<<n)-1 << "\n";
    for (int i = 0; i < (1 << n)-1; i++){
        if (turn){
            for (int i = 0; i < 3; i++){
                if (!towers[i].empty() && towers[i].top() == 1){
                    index = i;
                    break;
                }
            }
            towers[index].pop();
            towers[(index+dir+3)%3].push(1);
            turn = false;
            cout << index+1 << " " << (index+dir+3)%3+1 << "\n";
        }
        else{
            int disk = 17;
            for (int i = 0; i < 3; i++){
                if (!towers[i].empty() && towers[i].top() != 1 && towers[i].top() < disk){
                    disk = towers[i].top();
                    index = i;
                }
            }
            towers[index].pop();
            if (!towers[(index+dir+3)%3].empty() && towers[(index+dir+3)%3].top() < disk){
                towers[(index-dir+3)%3].push(disk);
                cout << index+1 << " " << (index-dir+3)%3+1 << "\n";
            }else{
                towers[(index+dir+3)%3].push(disk);
                cout << index+1 << " " << (index+dir+3)%3+1 << "\n";
            }
            turn = true;
        }
    }

    return 0;
}
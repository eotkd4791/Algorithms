#include <iostream>
#include <cmath>
using namespace std;

int N;
int K;

void hanoi(int h, int start, int through, int dest) {
    if(h == 1) {
        cout << start << ' ' << dest << '\n';
        return;
    }
    else {
        hanoi(h - 1, start, dest, through);
        cout << start << ' '<< dest << '\n';
        hanoi(h - 1, through, start, dest);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << (int) pow(2, N) - 1 << '\n';

    hanoi(N, 1, 2, 3);
    return 0;
}
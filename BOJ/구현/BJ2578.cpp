#include <iostream>
using namespace std;

const int L = 5;
int Board[L][L];
int Numbers[L*L];

int CheckLines() {
  int TotalCount = 0;
  for(int i=0; i<L; i++) {
    int RowCount = 0;
    int ColCount = 0;
    for(int j=0; j<L; j++) {
      if(Board[i][j] == 0) {
        RowCount++;
      }
      if(Board[j][i] == 0) {
        ColCount++;  
      }
    }
    TotalCount += (int) (RowCount == L) + (int) (ColCount == L);
  }
  return TotalCount;
}

int CheckDiagonals() {
  int FromTopLeft = 0;
  int FromTopRight = 0;
  for(int i=0; i<L; i++) {
    if(Board[i][i] == 0) {
      FromTopLeft++;
    }
    if(Board[i][L-i-1] == 0) {
      FromTopRight++;
    }
  }
  return (int) (FromTopLeft == L) + (int) (FromTopRight == L);
}

void MarkBingo(int Number) {
  for(int i=0; i<L; i++) {
    for(int j=0; j<L; j++) {
      if(Board[i][j] == Number) {
        Board[i][j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<L; i++) {
    for(int j=0; j<L; j++) {
      cin >> Board[i][j];
    }
  }

  int Number;
  for(int i=0; i<L*L; i++) {
    cin >> Number;
    Numbers[i] = Number;
  }

  for(int i=0; i<L*L; i++) {
    MarkBingo(Numbers[i]);
    if(CheckLines() + CheckDiagonals() >= 3) {
      cout << i + 1 << '\n';
      break;
    }
  }
  return 0;
}
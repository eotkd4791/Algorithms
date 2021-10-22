#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int Result;
int Quacks[5];
string Ducks;
stack<char> S;

bool CheckIfAllDucksPerfectQuack() {
  for(int i=1; i<5; i++) {
    if(Quacks[i-1] != Quacks[i]) {
      return false;
    }
  }
  return true;
}

bool CheckIfCorrect(int index) {
  int countQuack = Quacks[index];
  for(int i=0; i<index; i++) {
    if(countQuack > Quacks[i]) {
      return false;
    }
  }
  return true;
}

int GetIndex(char l) {
  switch(l) {
    case 'q': return 0;
    case 'u': return 1;
    case 'a': return 2;
    case 'c': return 3;
    default: return 4;
  }
}

bool IsWrongRecording() {
  int Size = (int) Ducks.size();
  for(int i=0; i<Size; i++) {
    char Letter = Ducks[i];
    int Index = GetIndex(Letter);
    Quacks[Index]++;
    if(!CheckIfCorrect(Index)) {
      return false;
    }
  }
  return true;
}

int CountDucks() {
  int Size = (int) Ducks.size();
  for(int i=0; i<Size; i++) {
    char Letter = Ducks[i];
    if(Letter == 'q') {
      S.push('q');
    } 
    else if(Letter == 'k') {
      S.pop();
    }
    Result = max(Result, (int) S.size());
  }
  return Result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Ducks;
  if(!IsWrongRecording() || !CheckIfAllDucksPerfectQuack()) {
    cout << -1 << '\n';
  }
  else {
    cout << CountDucks() << '\n';
  }
  return 0;
}
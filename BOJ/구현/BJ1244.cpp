#include <iostream>
using namespace std;

int N, M, Gender, Number;
int Switches[101];

void BoyControlSwitch(int SwitchNumber) {
  for(int i=1; i<=N; i++) {
    if(i % SwitchNumber == 0) {
      Switches[i] = (Switches[i] + 1) % 2;
    }
  }
}

void GirlControlSwitch(int SwitchNumber) {
  Switches[SwitchNumber] = (Switches[SwitchNumber] + 1) % 2;
  for(int i=1; i<=N; i++) {
    int Left = SwitchNumber - i;
    int Right = SwitchNumber + i;

    if(1 <= Left && Right <= N && Switches[Left] == Switches[Right]) {
      Switches[Left] = (Switches[Left] + 1) % 2;
      Switches[Right] = (Switches[Right] + 1) % 2;
    }
    else {
      break;
    }
  }
}

void ControlSwitches(int Student, int SwitchNumber) {
  if(Student == 1) {
    BoyControlSwitch(SwitchNumber);
  }
  else {
    GirlControlSwitch(SwitchNumber);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=1; i<=N; i++) {
    cin >> Switches[i];
  }

  cin >> M;
  for(int i=0; i<M; i++) {
    cin >> Gender >> Number;
    ControlSwitches(Gender, Number);
  }

  for(int i=1; i<=N; i++) {
    cout << Switches[i] << ' ';
    if(i % 20 == 0) {
      cout << '\n';
    }
  }
  return 0;
}
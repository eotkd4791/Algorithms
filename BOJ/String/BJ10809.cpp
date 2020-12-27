#include <iostream>
#include <cstring>
using namespace std;

int arr[30];
string str;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(arr, -1, sizeof(arr));

  cin >> str;

  for (int i = 0; i < str.size(); i++)
  {
    int index = str[i] - 'a';

    if (arr[index] == -1)
    {
      arr[index] = i;
    }
  }

  for (int i = 0; i < 26; i++)
    cout << arr[i] << ' ';

  return 0;
}

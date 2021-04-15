#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
  int answer = 0;
  string tmp = s + s;
  int size = s.size();

  for (int i = 0; i < size; i++)
  {
    stack<char> st;
    bool flag = true;
    for (int j = i; j < i + size; j++)
    {
      if (tmp[j] == '}' || tmp[j] == ']' || tmp[j] == ')')
      {
        if (!st.empty() && ((tmp[j] == '}' && st.top() == '{') || (tmp[j] == ']' && st.top() == '[') || (tmp[j] == ')' && st.top() == '(')))
          st.pop();
        else
        {
          flag = false;
          break;
        }
      }
      if (tmp[j] == '{' || tmp[j] == '[' || tmp[j] == '(')
        st.push(tmp[j]);
    }
    if (st.empty() && flag)
      answer++;
  }
  return answer;
}
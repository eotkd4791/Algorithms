#include <string>
#include <stack>
using namespace std;

bool isright(string str)
{
	if (str == "")
		return true;
	stack<char> s;
	bool flag = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			if (!s.empty())
				s.pop();
			else
			{
				flag = true;
				break;
			}
		}
	}
	if (!s.empty() || flag)
		return false;
	else
		return true;
}

string recur(string s) {
	if (s == "")
		return s;

	int left = 0; int right = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			left++;

		if (s[i] == ')')
			right++;

		if (left > 0 && right > 0 && left == right)
			break;
	}
	string u = s.substr(0, left + right);
	string v = "";
	if (left + right < s.size())
		v = s.substr(left + right, s.size() - (left + right));

	string V = recur(v);

	if (isright(u))
	{
		return u + V;
	}
	else
	{
		string tmp = "(";
		tmp += V;
		tmp.push_back(')');

		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(')
				tmp.push_back(')');
			else
				tmp.push_back('(');
		}
		return tmp;
	}
}

string solution(string p) {
	if (isright(p))
		return p;
	else
	{
		string answer = recur(p);
		return answer;
	}
}
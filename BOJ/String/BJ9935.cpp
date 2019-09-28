#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<char> dq;
	string str;
	string ex;

	cin >> str;
	cin >> ex;

	for (int i = 0; i < str.length(); i++) {
		dq.push_back(str[i]);

		if (str[i] == ex[ex.length() - 1]) {
			stack<char> s;
			for (int j = ex.length() - 1; j >= 0; j--) {
				if (!dq.empty() && dq.back() == ex[j]) {
					s.push(dq.back());
					dq.pop_back();
				}

				if (j == 0 && s.size() != ex.length()) {
					while (!s.empty()) {
						dq.push_back(s.top());
						s.pop();
					}
				}

			}
		}
	}

	if (dq.empty())
		cout << "FRULA";
	else
		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}
	return 0;
}
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int MIN = s.size();

	for (int i = 1; i <= s.size() / 2; i++)
	{
		int init = 0; int len = i; int cnt = 1;
		string tmp = ""; string ans = "";

		while (init <= s.size()) {
			if (tmp == s.substr(init, i)) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					while (cnt > 0) {
						ans.push_back('T');
						cnt /= 10;
					}
				}
				cnt = 1;
				tmp = s.substr(init, i);
			}
			init += i;
			if (cnt == 1)
				for (int j = 0; j < tmp.size(); j++)
					ans.push_back(tmp[j]);
		}
		MIN = MIN > ans.size() ? ans.size() : MIN;
	}
	return MIN;
}
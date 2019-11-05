#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool comp(pair<float, int> a, pair<float, int> b) {
	if (a.first > b.first)
		return true;

	else if (a.first == b.first)
		return (a.second < b.second);

	else
		return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	int done = stages.size();
	int yet[505] = {};

	for (int i = 0; i < stages.size(); i++) {
		yet[stages[i]]++;
	}

	vector<pair<float, int> > v;
	for (int i = 1; i <= N; i++) {

		if (yet[i] == 0) {
			v.push_back(make_pair(0, i));
		}
		else {
			float var = (float)yet[i] / done;
			v.push_back(make_pair(var, i));
			done -= yet[i];
		}
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		answer.push_back(v[i].second);
	}
	return answer;
}
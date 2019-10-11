#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int j = B.size() - 1; int cnt = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] < B[j]) {
			j--;
			cnt++;
		}
		else
			continue;
	}
	return cnt;
}
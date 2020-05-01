#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int N, inp;
vector<pair<int, int> > p, s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        p.clear();
        s.clear();
        int stlen[2] = {}, idx = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> inp;
                if (inp == 1) {
                    p.push_back(make_pair(i, j));
                } else if (inp > 1) {
                    s.push_back(make_pair(i, j));
                    stlen[idx++] = inp;
                }
            }
        }
        int ps = (int) p.size();

        vector<int> pick(ps, 0);
        for (int i = 0; i < ps; i++) {
            pick.push_back(1);
        }

        int MIN = 987654321;
        do {
            pair<int, int> arr[11] = {};
            queue<int> q[2], w[2];
            for (int i = 0; i < ps; i++) {
                int which = pick[i];
                int dist = abs(s[which].first - p[i].first) + abs(s[which].second - p[i].second);
                arr[i] = make_pair(dist, which);
            }

            sort(arr, arr + ps);

            int time = 0, cnt = 0;
            bool check[11] = {};

            while (time++ < 30) {
                for (int j = 0; j < ps; j++) {
                    if (check[j]) continue;
                    int which = arr[j].second;
                    if (arr[j].first < time) {
                        check[j] = true;
                        if (q[which].size() < 3) {
                            q[which].push(stlen[which]);
                        } else {
                            w[which].push(stlen[which]);
                        }
                    }
                }
                for (int i = 0; i < 2; i++) {
                    int qz = (int) q[i].size();
                    while (qz--) {
                        int oq = q[i].front();
                        q[i].pop();
                        if (oq > 0) q[i].push(oq - 1);
                        else {
                            cnt++;
                            if (!w[i].empty()) {
                                while (q[i].size() < 3) {
                                    q[i].push(w[i].front()-1);
                                    w[i].pop();
                                }
                            }
                        }
                    }
                }
                if (cnt == ps) {
                    MIN = MIN > time ? time : MIN;
                    break;
                }
            }
        } while (next_permutation(pick.begin(), pick.end()));
        cout << '#' << t << ' ' << MIN << '\n';
    }
    return 0;
}


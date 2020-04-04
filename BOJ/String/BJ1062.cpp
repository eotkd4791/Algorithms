#include <iostream>
#include <algorithm>

using namespace std;

int n, k, res;
string str[55], tmp;
bool check[30];

void recur(int idx, int cnt) {
    if (cnt == k) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < str[i].size(); j++) {
                if (!check[str[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        res = max(res, ans);
        return;
    }

    for (int i = idx; i < 26; i++) {
        if (!check[i]) {
            check[i] = true;
            recur(i + 1, cnt + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 4; j < tmp.size() - 4; j++) str[i] += tmp[j];
    }

    if (k < 5) {
        cout << 0 << '\n';
        return 0;
    } else if (k == 26) {
        cout << n << '\n';
        return 0;
    }
    k -= 5;
    check['a' - 'a'] = true;
    check['n' - 'a'] = true;
    check['t' - 'a'] = true;
    check['i' - 'a'] = true;
    check['c' - 'a'] = true;

    recur(0, 0);
    cout << res << '\n';

    return 0;
}
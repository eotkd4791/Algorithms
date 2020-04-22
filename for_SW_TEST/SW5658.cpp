#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n, k, num;

deque<char> dq;

vector<string> v;

void solve()
{
    for (int i = 0; i < 4; i++)
    {
        string str;

        for (int j = i * num; j < i * num + num; j++)
        {
            str += dq[j];
        }
        v.push_back(str);
    }
}

bool cmp(string a, string b) { return a > b; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        v.clear();

        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            char ch;

            cin >> ch;

            dq.push_back(ch);
        }
        solve();

        num = n / 4;

        for (int i = 0; i < num - 1; i++)
        {
            dq.push_front(dq.back());

            dq.pop_back();

            solve();
        }
        sort(v.begin(), v.end(), cmp);

        v.erase(unique(v.begin(), v.end()), v.end());

        char ch[20] = {};

        for (int i = 0; i < num; i++) ch[i] = v[k - 1][i];

        int res = (int) strtol(ch, NULL, 16);

        cout << '#' << t << ' ' << res << '\n';

        deque<char> temp; swap(dq, temp);
    }
    return 0;
}

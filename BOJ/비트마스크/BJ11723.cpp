#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 0, x = 0, s = 0; string str;

    cin >> n;

    while(n--)
    {
        cin >> str;

        if(str != "all" && str != "empty")
        {
            cin >> x;

            if(str == "add")
            {
                if((s & (1 << x)) > 0) continue;

                s |= (1 << x);
            }
            else if (str == "remove")
            {
                if((s & (1 << x)) > 0) s &= ~(1 << x);

            }
            else if (str == "check")
            {
                if ((s & (1 << x)) > 0) cout << 1 << '\n';

                else cout << 0 << '\n';
            }
            else // toggle
            {
                s ^= (1 << x);
            }
        }
        else
        {
            s = 0;

            if(str == "all")
            {
                s = (1 << 21) - 1;
            }
        }
    }
    return 0;
}
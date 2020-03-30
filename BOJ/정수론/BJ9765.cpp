#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c[7], x[7];

ll gcd(ll a, ll b) {  return b==0 ? a : gcd(b, a%b); }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i=1; i<=6; i++) cin >> c[i];

    x[2] = gcd(c[1],c[5]); x[1] = c[1] / x[2]; x[3] = c[5] / x[2];

    x[6] = gcd(c[3],c[6]); x[7] = c[3] / x[6]; x[5] = c[6] / x[6];

    for(int i=1; i<=7; i++) if(i!=4) cout << x[i] << ' ';

    return 0;
}
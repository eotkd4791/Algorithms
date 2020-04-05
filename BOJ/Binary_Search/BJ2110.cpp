#include <iostream>
#include <algorithm>

using namespace std;

int n, c, arr[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    int left = 1, right = arr[n - 1] - arr[0];

    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        int cnt = c - 1, prev = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - prev >= mid) {
                cnt--;
                prev = arr[i];
            }
        }
        if (cnt <= 0) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int a[1000];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int k;
        cin >> k;

        sort(a, a + n);

        int count = 0;
        int i = 0, j = 1;

        while (i < n && j < n) {
            if (i != j && a[j] - a[i] == k) {
                count++;
                i++;
                j++;
            } else if (a[j] - a[i] < k) {
                j++;
            } else {
                i++;
            }
        }

        cout << count << endl;
    }
    return 0;
}

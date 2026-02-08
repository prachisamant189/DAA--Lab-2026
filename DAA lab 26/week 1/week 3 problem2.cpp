#include <iostream>
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

        int comparisons = 0, swaps = 0;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                comparisons++;
                if (a[j] < a[minIndex])
                    minIndex = j;
            }
            if (minIndex != i) {
                swap(a[i], a[minIndex]);
                swaps++;
            }
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }
    return 0;
}

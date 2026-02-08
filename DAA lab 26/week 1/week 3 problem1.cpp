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

        int comparisons = 0, shifts = 0;

        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;

            while (j >= 0) {
                comparisons++;
                if (a[j] > key) {
                    a[j + 1] = a[j];
                    shifts++;
                    j--;
                } else {
                    break;
                }
            }
            a[j + 1] = key;
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "shifts = " << shifts << endl;
    }
    return 0;
}

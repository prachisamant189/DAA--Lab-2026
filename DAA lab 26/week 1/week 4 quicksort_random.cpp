#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;
long long swapsCount = 0;

int partitionArray(vector<int>& a, int l, int r) {
    int pivotIndex = l + rand() % (r - l + 1);
    swap(a[pivotIndex], a[r]);
    swapsCount++;

    int pivot = a[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        comparisons++;
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
            swapsCount++;
        }
    }

    swap(a[i + 1], a[r]);
    swapsCount++;

    return i + 1;
}

void quickSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int pi = partitionArray(a, l, r);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        comparisons = 0;
        swapsCount = 0;

        quickSort(a, 0, n - 1);

        for(int x : a) cout << x << " ";
        cout << "\n";
        cout << "comparisons = " << comparisons << "\n";
        cout << "swaps = " << swapsCount << "\n";
    }
}

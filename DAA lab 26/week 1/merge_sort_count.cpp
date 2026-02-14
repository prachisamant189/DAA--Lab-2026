#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;
long long inversions = 0;

void mergeArray(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++) left[i] = a[l + i];
    for(int i = 0; i < n2; i++) right[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        comparisons++;
        if(left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
            inversions += (n1 - i);
        }
    }

    while(i < n1) a[k++] = left[i++];
    while(j < n2) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeArray(a, l, m, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        comparisons = 0;
        inversions = 0;

        mergeSort(a, 0, n - 1);

        for(int x : a) cout << x << " ";
        cout << "\n";
        cout << "comparisons = " << comparisons << "\n";
        cout << "inversions = " << inversions << "\n";
    }
}

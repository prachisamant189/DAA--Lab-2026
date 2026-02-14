#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& a, int l, int r) {
    int pivot = a[r];
    int i = l;

    for(int j = l; j < r; j++) {
        if(a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[r]);
    return i;
}

int quickSelect(vector<int>& a, int l, int r, int k) {
    if(l <= r) {
        int pi = partitionArray(a, l, r);

        if(pi == k) return a[pi];
        else if(pi > k) return quickSelect(a, l, pi - 1, k);
        else return quickSelect(a, pi + 1, r, k);
    }
    return -1;
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

        int k;
        cin >> k;

        if(k > n || k <= 0) {
            cout << "not present\n";
            continue;
        }

        int result = quickSelect(a, 0, n - 1, k - 1);
        cout << result << "\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
long long minTransformationOperations(int n, vector<long long>& a, long long k) {
    if (n==0) return 0;
    long long target_remainder=a[0] % k;
    vector<long long> steps_array(n);
    for (int i=0;i<n;++i) {
        if (a[i]%k!=target_remainder) {
            return -1; 
        }
        steps_array[i] = a[i] / k;
    }
    sort(steps_array.begin(), steps_array.end());
    long long median = steps_array[n / 2];
    long long min_operations = 0;
    for (int i=0;i<n;++i) {
        min_operations += abs(steps_array[i] - median);
    }
    return min_operations;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<long long> a(n);
        for (int i=0;i<n;++i) {
            cin >> a[i];
        }
        long long k;
        cin >> k;
        cout << minTransformationOperations(n, a, k) << "\n";
    }
    return 0;
}
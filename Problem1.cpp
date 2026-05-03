#include<bits/stdc++.h>
using namespace std;
int maxCyclicSubstringSum(string s) {
    int n=s.length();
    string ss=s+s;
    int max_sum=0;
    int current_sum=0;
    vector<bool> in_window(26, false);
    int L=0;
    for (int R=0;R<2*n-1;++R) {
        int char_idx=ss[R]-'a';
        int char_val=char_idx+1;
        while (in_window[char_idx] || (R - L + 1) > n) {
            in_window[ss[L] - 'a']=false;
            current_sum-=(ss[L] - 'a' + 1);
            L++;
        }
        in_window[char_idx]=true;
        current_sum+=char_val;
        max_sum=max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (cin >> s) {
        cout << maxCyclicSubstringSum(s) << "\n";
    }
    return 0;
}
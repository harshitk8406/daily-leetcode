class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long tot = 0;
        for (int x : beans){
            tot += x;
        }
        long long ans = LLONG_MAX;
        int n = beans.size();

        for (int i=0; i<n; i++){
            long long rem = n-i;
            long long a = tot - 1LL * beans[i] * rem;
            ans = min(ans, a);
        }
        return ans;
    }
};
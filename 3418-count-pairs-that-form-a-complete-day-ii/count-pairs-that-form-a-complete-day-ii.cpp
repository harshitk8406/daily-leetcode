class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnt(24);
        for (int i=0; i<hours.size(); i++){
            ans += cnt[(24-hours[i]%24)%24];
            cnt[hours[i]%24]++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> freq(mx+1, 0);
        for (int x : nums)
            freq[x]++;
        
        vector<long long> cnt(mx+1, 0);
        for (int i=1; i<=mx; i++){
            for (int j=i; j<=mx; j+=i){
                cnt[i] += freq[j];
            }
        }

        vector<long long> pairs(mx+1, 0);
        for (int i=mx; i>=1; i--){
            pairs[i] = cnt[i] * (cnt[i]-1) / 2;
            for (int j=2*i; j<=mx; j+=i){
                pairs[i] -= pairs[j];
            }
        }

        vector<long long> pref(mx+1, 0);
        for (int i=1; i<=mx; i++){
            pref[i] = pref[i-1] + pairs[i];
        }

        vector<int> arr;
        for (long long q : queries){
            int i = lower_bound(pref.begin(), pref.end(), q+1) - pref.begin();
            arr.push_back(i);
        }
        return arr;
    }
};
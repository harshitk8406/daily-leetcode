class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for (char ch : word){
            mp[ch-'a']++;
        }

        sort(mp.begin(), mp.end());
        int ans = 0;
        for (int i=25, cnt=0; i>=0; i--){
            int curr = 25-i;
            if (curr%8==0)
                cnt++;
            ans += mp[i] * cnt;
        }
        return ans;
    }
};
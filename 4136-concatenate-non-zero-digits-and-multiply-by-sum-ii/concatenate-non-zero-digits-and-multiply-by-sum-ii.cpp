class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        int n = s.size();
        vector<long long> pw10(n+1,1);
        for (int i=1; i<=n; i++){
            pw10[i] = (pw10[i-1]*10)%mod;
        }
        vector<int> idx(n+1, 0);
        vector<long long> val(n+1, 0);
        vector<long long> tot(n+1, 0);
        int cnt = 0;

        for (int i=0; i<n; i++){
            int dig = s[i]-'0';
            if (dig!=0){
                cnt++;
                val[cnt] = (val[cnt-1]*10+dig)%mod;
                tot[cnt] = tot[cnt-1]+dig;
            }
            idx[i+1] = cnt;
        }

        vector<int> ans;
        for (auto q : queries){
            int l = q[0];
            int r = q[1];
            int left = idx[l];
            int right = idx[r+1];
            if (left==right){
                ans.push_back(0);
                continue;
            }

            int len = right-left;

            long long num = (val[right] - val[left] * pw10[len])%mod;
            if (num<0)
                num += mod;
            
            long long sum = tot[right] - tot[left];
            ans.push_back((num*sum)%mod);
        }
        return ans;
    }
};
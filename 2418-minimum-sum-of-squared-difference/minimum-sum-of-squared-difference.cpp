class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff((int)1e5+1);
        for (int i=0; i<nums1.size(); i++){
            diff[abs(nums1[i] - nums2[i])]++;
        }

        int val = 0;
        int left = k1+k2;
        int ans = 0;

        for (int i=(int)1e5; i>=0; i--){
            ans = diff[i];
            if (ans <= left){
                if (i<=1)
                    return 0;
                
                diff[i-1] += diff[i];
                diff[i] = 0;
                left -= ans;
            }
            else{
                if (i==0)
                    return 0;

                diff[i] -= left;
                diff[i-1] += left;
                break;
            }
        }

        long long res = 0;
        for (int i=1LL; i<=1e5; i++){
            res += (long long)diff[i] * ((long long)i*i);
        }
        return res;
    }
};
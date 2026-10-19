class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1;
        int lm=0, rm=0;
        int ans = 0;

        while(left < right){
            if (height[left] <= height[right]){
                if (lm < height[left])
                    lm = height[left];
                else
                    ans += lm - height[left];
                left++;
            }
            else {
                if (rm < height[right])
                    rm = height[right];
                else
                    ans += rm - height[right];
                right--;
            }
        }
        return ans;
    }
};
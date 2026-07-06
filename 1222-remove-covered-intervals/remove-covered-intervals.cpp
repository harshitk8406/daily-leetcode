class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](auto &x){
            return pair{x[0], -x[1]};
        });

        int ans = 0;
        int r = 0;
        for (auto &x : intervals){
            ans += x[1] > r;
            r = max(r, x[1]);
        }
        return ans;
    }
};
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        int n = arr1.size();
        int m = arr2.size();
        ranges::sort(arr2);

        for (int x : arr1){
            auto it = lower_bound(arr2.begin(),arr2.end(), x);
            bool flag = true;

            if (it!=arr2.end() && abs(*it-x)<=d)
                flag = false;
            if (it!=arr2.begin() && abs(*(it-1)-x) <= d)
                flag = false;
            
            if (flag)
                cnt++;
        }
        return cnt;
    }
};
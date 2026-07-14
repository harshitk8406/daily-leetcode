class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left=0;
        int right=n-1;
        int mid = arr[(n-1)/2];

        while(--k>=0){
            if (mid-arr[left] > arr[right]-mid)
                ++left;
            else
                --right;
        }
        arr.erase(arr.begin()+left, arr.begin()+right+1);
        return arr;
    }
};
class Solution {
public:
    vector<int> toBin(int n){
        vector<int> arr;
        while(n>0){
            arr.push_back(n%2);
            n/=2;
        }
        //reverse(arr.begin(), arr.end());
        return arr;
    }

    bool hasAlternatingBits(int n) {
        vector<int> arr = toBin(n);
        for (int i=0; i<arr.size()-1; i++){
            if (arr[i]==arr[i+1])
                return false;
        }
        return true;
    }
};
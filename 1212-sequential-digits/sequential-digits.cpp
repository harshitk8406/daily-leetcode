class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> arr;
        string str = "123456789";
        string l = to_string(low);
        string r = to_string(high);

        for (int i=l.size(); i<=r.size(); i++){
            for (int j=0; j<=9-i; j++){
                string n = str.substr(j,i);
                int num = stoi(n);
                if (num >= low && num <= high)
                    arr.push_back(num);
            }
        }
        return arr;
    }
};
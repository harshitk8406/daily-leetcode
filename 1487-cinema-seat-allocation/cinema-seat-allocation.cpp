class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n*2;
        sort(reservedSeats.begin(), reservedSeats.end());
        for (int i=0; i<reservedSeats.size(); i++){
            int curr = reservedSeats[i][0];
            bool flag25=true, flag47=true, flag69=true;

            while(i<reservedSeats.size() && reservedSeats[i][0]==curr){
                if (reservedSeats[i][1] >= 2 && reservedSeats[i][1] <= 5){
                    flag25 = false;
                    if (reservedSeats[i][1] >= 4 && reservedSeats[i][1]<=5)
                        flag47 = false;
                }
                else if (reservedSeats[i][1] >= 6 && reservedSeats[i][1] <= 9){
                    flag69 = false;
                    if (reservedSeats[i][1] >= 6 && reservedSeats[i][1]<=7)
                        flag47 = false;
                }
                i++;
            }

            if (!flag69 && !flag25 && !flag47)
                ans-=2;
            else if (!flag69 || !flag25 || !flag47)
                ans--;
            i--;
        }
        return ans;
    }
};
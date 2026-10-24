class Solution {
public:
    auto toDay(string &str, int arr[]){
        int m = (str[0]-'0')*10 + (str[1]-'0');
        int d = (str[3]-'0')*10 + (str[4]-'0');
        int ans = d;
        for (int i=0; i<m-1; i++){
            ans += arr[i];
        }
        return ans;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aStart = toDay(arriveAlice, arr);
        int aEnd = toDay(leaveAlice, arr);
        int bStart = toDay(arriveBob, arr);
        int bEnd = toDay(leaveBob, arr);

        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        if (start <= end)
            return end-start+1;
        return 0;
    }
};
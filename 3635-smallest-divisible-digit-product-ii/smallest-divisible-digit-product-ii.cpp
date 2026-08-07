class Solution {
public:
    int primes[4] = {2,3,5,7};
    int maxPrime = 7;

    void logNum(int primeCnt[], char ch, int val){
        if (ch < '2')
            return;
        if (ch=='9')
            primeCnt[3] += val*2;
        else if (ch=='4')
            primeCnt[2] += val*2;
        else if (ch=='8')
            primeCnt[2] += val*3;
        else if (ch=='6'){
            primeCnt[2] += val;
            primeCnt[3] += val;
        }
        else
            primeCnt[ch-'0'] += val;
    }

    string buildSuffix(int primeCnt[], int len, string str){
        int idx = str.size();

        while(primeCnt[3] > 1){
            primeCnt[3]-=2;
            str[--idx] = '9';
        }

        while(primeCnt[2] > 2){
            primeCnt[2]-=3;
            str[--idx] = '8';
        }

        while(primeCnt[7]-- > 0){
            str[--idx] = '7';
        }

        if (primeCnt[2] > 0 && primeCnt[3]>0){
            str[--idx] = '6';
            primeCnt[2]--;
            primeCnt[3]--;
        }

        while (primeCnt[5]-- > 0) {
            str[--idx] = '5';
        }

        while (primeCnt[2] > 1) {
            primeCnt[2] -= 2;
            str[--idx] = '4';
        }

        while (primeCnt[3] > 0) {
            primeCnt[3]--;
            str[--idx] = '3';
        }

        while (primeCnt[2] > 0) {
            primeCnt[2]--;
            str[--idx] = '2';
        }

        while (idx + len != (int)str.length()) {
            str[--idx] = '1';
        }

        if (len == (int)str.length()) {
            return str;
        }

        return str.substr(1, str.length() - 1);
    }

    int getMinLen(int primeCnt[]) {
        int count2 = max(0, primeCnt[2]);
        int count3 = max(0, primeCnt[3]);

        int count23 = (count3 & 1) + (count2 % 3);

        return (count3 >> 1) + (count2 / 3) + max(0, primeCnt[7]) + max(0, primeCnt[5]) + (count23 == 3 ? 2 : count23 > 0 ? 1 : 0);
    }

    string smallestNumber(string num, long long t) {
        int primeCnt[8] = {0};
        int n = num.size();
        int minLen;
        int zero = 0;

        for (int prime : primes){
            while(t%prime==0){
                t/=prime;
                primeCnt[prime]++;
            }
        }

        if (t!=1)
            return "-1";
        
        minLen = getMinLen(primeCnt);
        if (n < minLen)
            return buildSuffix(primeCnt, minLen, string(minLen, ' '));
        
        string str(n+ 1, ' ');
        int i=0;
        while(zero < n){
            str[++i] = num[zero];
            if (str[i]=='0')
                break;
            
            logNum(primeCnt, str[i], -1);
            zero++;
        }

        if (getMinLen(primeCnt)==0){
            if (zero==n)
                return num;
            
            fill(str.begin() + (++zero), str.end(), '1');
            return str.substr(1, n);
        }

        int last = n-1;
        int end = min(zero, last);

        for (; end>=0; end--){
            logNum(primeCnt, str[end+1], 1);

            while(++str[end+1] <= '9'){
                logNum(primeCnt, str[end+1], -1);

                if (getMinLen(primeCnt) <= last - end){
                    return buildSuffix(primeCnt, last-end, str);
                }

                logNum(primeCnt, str[end+1], 1);
            }
        }

        return buildSuffix(primeCnt, str.length(), str);
    }
};
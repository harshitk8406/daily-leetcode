class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<long long> arr;
        for (int coin : coins) {
            bool redundant = false;

            for (long long prev : arr) {
                if (coin % prev == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant) {
                arr.push_back(coin);
            }
        }

        long long high = arr[0] * 1LL * k;
        long long low = 1;

        int m = arr.size();
        int totalMasks = 1 << m;

        vector<long long> lcms(totalMasks, 1);

        vector<int> signs(totalMasks, 1);

        for (int mask = 1; mask < totalMasks; ++mask) {
            long long currentLCM = 1;
            int bits = 0;

            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    long long g = std::gcd(currentLCM, arr[i]);

                    currentLCM = currentLCM / g;

                    if (currentLCM > high / arr[i]) {
                        currentLCM = high + 1;
                        break;
                    }

                    currentLCM *= arr[i];
                    ++bits;
                }
            }

            lcms[mask] = currentLCM;

            signs[mask] = (bits % 2 == 1) ? 1 : -1;
        }

        auto count = [&](long long x) {
            long long result = 0;

            for (int mask = 1; mask < totalMasks; ++mask) {
                if (lcms[mask] <= x) {
                    result += signs[mask] * (x / lcms[mask]);
                }
            }

            return result;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
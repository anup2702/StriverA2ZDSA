// #include <vector>
// #include <cmath>
// #include <algorithm>
// using namespace std;

class Solution {
public:
    long long maxArr(vector<int>& piles) {
        return *max_element(piles.begin(), piles.end());
    }

    long long totalHours(vector<int>& piles, long long hours) {
        long long th = 0;
        for (int i = 0; i < piles.size(); i++) {
            th += ceil((double)piles[i] / hours);
        }
        return th;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = maxArr(piles);
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long tHour = totalHours(piles, mid);
            if (tHour <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
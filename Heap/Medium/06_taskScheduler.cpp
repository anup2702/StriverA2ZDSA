class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        int maxFreq = 0;
        for (char c : tasks) {
            int idx = c - 'A';
            ++freq[idx];
            maxFreq = max(maxFreq, freq[idx]);
        }
        int maxFreqCnt = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                ++maxFreqCnt;
            }
        }
        int minimumSlots = (maxFreq - 1) * (n + 1) + maxFreqCnt;
        // return max(n, minimumSlots);
        return max(static_cast<int>(tasks.size()), minimumSlots);
    }
};
// if max freq is x and need n intervals, for each time n+1 idle time to wait
// add s for last freq
// n if all are differents
class Solution {
public:
    int getMaxCount(vector<int>& freq) {
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, freq[i]);
        }
        return maxCount;
    }

    int getMinCount(vector<int>& freq) {
        int minCount = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                minCount = min(minCount, freq[i]);
            }
        }
        return minCount;
    }
    int beautySum(string s) {
        int sum = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};
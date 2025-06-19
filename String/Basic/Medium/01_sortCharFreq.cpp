class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> freqMap;

        for (char ch : s)
        {
            freqMap[ch]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto &entry : freqMap)
        {
            maxHeap.push({entry.second, entry.first});
        }

        string result;
        while (!maxHeap.empty())
        {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(freq, ch);
        }

        return result;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for(int el: hand){
            freq[el]++;
        }
        for(int h: hand){
            if(freq.find(h) == freq.end()) continue; // skip same cards
            for(int i=h; i<h+groupSize; i++){
                if(freq.find(i) == freq.end()) return false; // req exists or not
                freq[i]--;
                if(freq[i]==0) freq.erase(i);
            }
        }
        return true;
    }
};
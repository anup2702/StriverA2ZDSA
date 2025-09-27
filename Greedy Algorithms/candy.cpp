class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i=1, sum = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak += 1;
                i++;
                sum += peak;
            }
            int down = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                down += 1;
                i++;
                sum += down;
            }
            down++;
            if(down > peak) sum += down-peak;
        }
        return sum;
    }
};
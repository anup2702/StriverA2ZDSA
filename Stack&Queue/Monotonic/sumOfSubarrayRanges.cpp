class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans += (long long)arr[i] * left * right;
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            ans += (long long)arr[i] * left * right;
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

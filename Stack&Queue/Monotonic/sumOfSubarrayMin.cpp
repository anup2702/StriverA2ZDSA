class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + arr[i] * left % mod * right % mod) % mod;
        }
        return ans;
    }
};


// a[i] can be min of multiple subarray
// calculate in how many subarray a[i] is min
// sum += a[i] * no. of subarray where it is min
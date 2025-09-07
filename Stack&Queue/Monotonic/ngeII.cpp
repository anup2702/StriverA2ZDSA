class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n, -1);
        for(int i=2*n-1; i>= 0; i--){
            while(!st.empty() and st.top() <= arr[i%n]) st.pop();
            if(i < n){
                if(!st.empty()) nge[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};
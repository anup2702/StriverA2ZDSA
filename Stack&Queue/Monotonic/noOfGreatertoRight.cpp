class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // Your code goes here
        int n = arr.size();
        int a = 0, b = 0;
        for(int i=n-1; i>= 0; i--){
            if(arr[i]>arr[indices[1]] and i > indices[1]) b++;
            if(arr[i]>arr[indices[0]] and i > indices[0]) a++;
        }
        return {a,b};
        
    }
};


class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> ngeCount(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= arr[i])
                st.pop();
            ngeCount[i] = st.size();
            st.push(arr[i]);
        }
        vector<int> ans;
        for(int idx : indices) {
            ans.push_back(ngeCount[idx]);
        }

        return ans;
    }
};

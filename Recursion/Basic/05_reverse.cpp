// User function Template for C++

class Solution {
  public:
  void insert(stack<int> &st, int el){
      if(st.size() == 0){
          st.push(el);
          return;
      }
      int k = st.top();
      st.pop();
      insert(st, el);
      st.push(k);
  }
    void Reverse(stack<int> &st) {
        if(st.size() == 1) return; 
        int k = st.top();
        st.pop();
        Reverse(st);
        insert(st, k);
    }
};
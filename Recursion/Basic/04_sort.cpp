void insert(stack<int> &s, int el){
      if(s.size() == 0 or s.top()<=el){
          s.push(el);
          return;
      }
      int k = s.top();
      s.pop();
      insert(s, el);
      s.push(k);
  }
  // Reverse the stack using recursion remove s.top<=el condition
  
void SortedStack ::sort() {
    // Your code here
    if(s.size() == 1) return; 
    int k = s.top();
    s.pop();
    sort();
    insert(s, k);
}
priority_queue<int> pq; // maxHeap
for (int num : nums)
{
  pq.push(num);
  if (pq.size() > k)
    pq.pop();
}
return pq.top();
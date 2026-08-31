// Last updated: 8/31/2026, 11:38:08 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        priority_queue< int, vector<int>, greater<int> > pq;
5        int n = nums.size();
6        
7        for(int i = 0; i < n; i++) {
8            if(pq.size() == k && pq.top() < nums[i]) {
9                pq.pop();
10                pq.push(nums[i]);
11            }
12            if(pq.size() < k)
13                pq.push(nums[i]);        
14        }
15        return pq.top();
16    }
17};
// Last updated: 7/27/2026, 2:13:13 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int firstMax = INT_MIN;
5        int secondMax = INT_MIN;
6
7        int firstMin = INT_MAX;
8        int secondMin = INT_MAX;
9
10        int n = nums.size();
11        for(int i = 0 ; i<n ; i++){
12            if(nums[i] >= firstMax){
13                secondMax = firstMax;
14                firstMax = nums[i];
15            }
16            else if(nums[i] >= secondMax){
17                secondMax = nums[i];
18            }
19            if(nums[i] <= firstMin){
20                secondMin = firstMin;
21                firstMin = nums[i];
22            }
23            else if(nums[i] < secondMin){
24                secondMin = nums[i];
25            }
26        }
27        return max((firstMax - 1) * (secondMax - 1) , (firstMin - 1) * (secondMin - 1));
28    }
29};
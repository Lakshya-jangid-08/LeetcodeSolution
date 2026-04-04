// Last updated: 4/4/2026, 12:59:41 pm
1class Solution {
2    set<vector<int>> res;
3    void solve(vector<int> &nums, int idx, int target, vector<int>& temp) {
4        if(target == 0) {
5            res.insert(temp);
6            return;
7        }
8        if(target < 0 || idx == nums.size()) return;
9
10        for(int i = idx; i < nums.size(); i++) {
11            if(i > idx && nums[i-1] == nums[i])   continue;
12            if(target - nums[i] >= 0) {
13                temp.push_back(nums[i]);
14                solve(nums, i + 1, target - nums[i], temp);
15                temp.pop_back();
16            } else {
17                break;
18            }
19        }
20
21        return;
22    }
23public:
24    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
25        sort(nums.begin(), nums.end());
26        vector<int> temp;
27        solve(nums, 0, target, temp);
28        return vector<vector<int>> (res.begin(), res.end());
29    }
30};
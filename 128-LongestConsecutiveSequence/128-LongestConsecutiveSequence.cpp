// Last updated: 8/4/2026, 3:19:21 PM
1class Solution {
2public:
3    int longestConsecutive(std::vector<int>& nums) {
4        if (nums.empty()) {
5            return 0;
6        }
7
8        unordered_set<int> numSet(nums.begin(), nums.end());
9        int longestStreak = 0;
10
11        for (int num : numSet) {
12            // Check if 'num' is the start of a sequence
13            if (numSet.find(num - 1) == numSet.end()) {
14                int currentNum = num;
15                int currentStreak = 1;
16
17                // Count how long the streak is
18                while (numSet.find(currentNum + 1) != numSet.end()) {
19                    currentNum++;
20                    currentStreak++;
21                }
22                
23                longestStreak = max(longestStreak, currentStreak);
24            }
25        }
26
27        return longestStreak;
28    }
29};
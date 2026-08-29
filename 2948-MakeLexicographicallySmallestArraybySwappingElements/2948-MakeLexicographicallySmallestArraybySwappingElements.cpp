// Last updated: 8/29/2026, 11:56:54 PM
1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
4        vector<int> numsSorted(nums);
5        sort(numsSorted.begin(), numsSorted.end());
6
7        int currGroup = 0;
8        unordered_map<int, int> numToGroup;
9        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));
10
11        unordered_map<int, list<int>> groupToList;
12        groupToList.insert(
13            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));
14
15        for (int i = 1; i < nums.size(); i++) {
16            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
17                // new group
18                currGroup++;
19            }
20
21            // assign current element to group
22            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));
23
24            // add element to sorted group list
25            if (groupToList.find(currGroup) == groupToList.end()) {
26                groupToList[currGroup] = list<int>();
27            }
28            groupToList[currGroup].push_back(numsSorted[i]);
29        }
30
31        // iterate through input and overwrite each element with the next
32        // element in its corresponding group
33        for (int i = 0; i < nums.size(); i++) {
34            int num = nums[i];
35            int group = numToGroup[num];
36            nums[i] = *groupToList[group].begin();
37            groupToList[group].pop_front();
38        }
39
40        return nums;
41    }
42};
// Last updated: 8/14/2026, 10:14:40 AM
1class Solution {
2public:
3    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
4        int n = fruits.size();
5        vector<bool> used(n, false); 
6        int unplaced = 0;
7
8        for (int i = 0; i < n; i++) {
9            bool placed = false;
10            for (int j = 0; j < n; j++) {
11                if (!used[j] && baskets[j] >= fruits[i]) {
12                    used[j] = true;
13                    placed = true;
14                    break;
15                }
16            }
17            if (!placed) {
18                unplaced++;
19            }
20        }
21        return unplaced;
22    }
23};
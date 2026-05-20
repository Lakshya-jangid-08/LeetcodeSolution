// Last updated: 5/20/2026, 11:25:26 PM
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5        vector<int> prefixCommonArray(n);
6
7        // Loop through each index to calculate common elements for each prefix
8        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
9            int commonCount = 0;
10
11            // Compare elements in A and B within the range of current prefix
12            for (int aIndex = 0; aIndex <= currentIndex; ++aIndex) {
13                for (int bIndex = 0; bIndex <= currentIndex; ++bIndex) {
14                    // Check if elements match, and count if they do
15                    if (A[aIndex] == B[bIndex]) {
16                        ++commonCount;
17                        break;
18                    }
19                }
20            }
21
22            // Store the count of common elements for the current prefix
23            prefixCommonArray[currentIndex] = commonCount;
24        }
25
26        // Return the final array with counts of common elements in each prefix
27        return prefixCommonArray;
28    }
29};
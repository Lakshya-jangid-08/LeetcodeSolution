// Last updated: 7/4/2026, 10:38:01 AM
1class Solution {
2    void flip(vector<int> &arr, int k) {
3        for(int i = 0; i < k/2; i+=1) {
4            swap(arr[i], arr[k - 1 - i]);
5        }
6        return;
7    }
8public:
9    vector<int> pancakeSort(vector<int>& arr) {
10        int n = arr.size();
11        vector<int> res;
12
13        for(int num = 1; num <= n; num++) {
14            for(int i = 0; i < n - num; i++) {
15                if(arr[i] == num) {
16                    flip(arr, i + 1);
17                    res.push_back(i + 1);
18                    flip(arr, n - num + 1);
19                    res.push_back(n - num + 1);
20                    break;
21                }
22            }
23        }
24        // O(N * N * N);
25
26        res.push_back(n);
27        flip(arr, n);
28        return res;
29    }
30};
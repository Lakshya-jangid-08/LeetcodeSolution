// Last updated: 8/4/2026, 3:39:46 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        map<int, unordered_set<int>> freqToElem;
5        unordered_map<int, int> elemToFreq;
6
7        for(int i = 0; i < nums.size(); i++) {
8            elemToFreq[nums[i]]++;
9        }
10
11        for(const auto &[elem, freq] : elemToFreq) {
12            freqToElem[freq].insert(elem);
13        }
14        vector<int> res;
15        for (auto it = freqToElem.rbegin(); it != freqToElem.rend(); it++) {
16            auto &[_, st] = *it;
17            for(auto x : st) {
18                res.push_back(x);
19                if(res.size() == k) return res;
20            }
21        }
22        return res;
23    }
24};
// Last updated: 6/29/2026, 10:21:45 AM
class Solution {
public:
    int minJumps(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, vector<int>> idxmp;
        
        for(int i = 0; i < n; i++) {
            idxmp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visit(n, false);

        q.push(0);
        int ans = 0;
        while(!q.empty()) {         
            int len  = q.size();
            while(len--) {
                int idx = q.front(); q.pop();

                if(idx == n - 1) return ans;
                
                visit[idx] = true;

                if(idx > 0 && visit[idx - 1] != true) {
                    q.push(idx - 1);
                    visit[idx - 1] = true;
                } 

                if(idx < n - 1 && visit[idx + 1] != true) {
                    q.push(idx + 1);
                    visit[idx + 1] = true;
                }

                for(auto idx2 : idxmp[nums[idx]]) {
                    if(visit[idx2]) continue;
                    q.push(idx2);
                    visit[idx2] = true;
                }

                idxmp[nums[idx]].clear();
            }
            ans += 1;
        }
        return ans;
    }
};
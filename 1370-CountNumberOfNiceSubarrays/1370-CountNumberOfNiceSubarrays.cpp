// Last updated: 6/29/2026, 10:21:52 AM
class Solution {
 public:
    int helper(vector<int>& nums, int k){
        if(k<0) return 0;
        int count=0;
        int sub=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & 1) count++;
            while(count>k){
                if(nums[l] & 1) count--;
                l++;
            }
            sub+=(i-l+1);
        }
        return sub;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (helper(nums,k)-helper(nums,k-1));
    }
};
// Last updated: 4/15/2026, 10:14:22 PM
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
        // cout<<helper(nums,k)<<" "<<helper(nums,k-1);
        return (helper(nums,k)-helper(nums,k-1));
    }
};
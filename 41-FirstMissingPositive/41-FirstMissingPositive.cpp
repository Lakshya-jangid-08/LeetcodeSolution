// Last updated: 4/4/2026, 11:13:28 pm
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int count=0;

       // for(auto i: nums) if(i>0) count++;

        // missing number can be the range of 1 to count+1 inclusive
        //count++;
        // int sum = count*(count+1) /2;
        //int sum2=0;
        //for(auto i:nums) if(i<=count && i>0) sum2+=i;

        // return sum-sum2;

        for(int i=0;i<nums.size();i++)
        {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        //for(auto i: nums) cout<<i<<" ";
        for(int i=0;i<nums.size();i++)
        {
            if(i+1!=nums[i]) return i+1;
        }




        return nums.size()+1;
    }
};
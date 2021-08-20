class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            while(low<high and nums[low]==nums[low+1]){
                low++;
            }
            while(low<high and nums[high]==nums[high-1]){
                high--;
            }
            
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<nums[low]){
                if(target>nums[mid] and nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(target<nums[mid] and nums[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return false;
    }
};
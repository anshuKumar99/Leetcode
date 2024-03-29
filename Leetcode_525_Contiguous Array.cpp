/*

LEETCODE LINK : https://leetcode.com/problems/contiguous-array/description/

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 
Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0,maxLen=0,currLen=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum+=1;
            }
            else{
                sum-=1;
            }
            if(mp.find(sum)!=mp.end()){
                currLen=i-mp[sum];
            }
            else{
                mp[sum]=i;
            }
            maxLen=max(maxLen,currLen);
        }
        return maxLen;
        
    }
};

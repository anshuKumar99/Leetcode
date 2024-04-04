/*

LEETCODE LINK : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 
Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

*/

class Solution {
public:
    //Total count of subarrays having <= k distict elements
    int slidingWindow(vector<int>& nums, int k){
        int n=nums.size();
        unordered_map<int,int> mp;

        int i=0,j=0,cnt=0;

        while(j<n){
            mp[nums[j]]++;
            while(i<n && mp.size()>k){
                //shrink the window
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt+=j-i+1;//total subarray ending at j
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums,k)-slidingWindow(nums,k-1);
    }
};
